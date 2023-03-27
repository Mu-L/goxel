
import * as std from 'std'

goxel.registerFormat({
  name: 'Test',
  ext: 'test\0*.test\0',
  export: function(img, path) {
    try {
      console.log(`Save ${path}`)
      let out = std.open(path, 'w')
      let volume = img.getLayersVolume()
      volume.iter(function(p, c) {
        console.log(`${p.x} ${p.y}, ${p.z} => ${c.r}, ${c.g}, ${c.b}`)
      })
      out.close()
      console.log('done')
    } catch(e) {
      console.log('error', e)
    }
  },
})

function getRandomColor() {
  return [
    Math.floor(Math.random() * 256),
    Math.floor(Math.random() * 256),
    Math.floor(Math.random() * 256),
    255
  ]
}

goxel.registerScript({
  name: 'FillRandom',
  description: 'Fill selection with random voxels',
  onExecute: function() {
    let box = goxel.selection
    if (!box) {
      console.log('Need a selection')
      return
    }
    let volume = goxel.image.activeLayer.volume
    box.iterVoxels(function(pos) {
      volume.setAt(pos, getRandomColor())
    })
  }
})

goxel.registerScript({
  name: 'Dilate',
  onExecute: function() {
    let volume = goxel.image.activeLayer.volume
    volume.copy().iter(function(pos, color) {
      for (let z = -1; z < 2; z++) {
        for (let y = -1; y < 2; y++) {
          for (let x = -1; x < 2; x++) {
            volume.setAt([pos.x + x, pos.y + y, pos.z + z], color)
          }
        }
      }
    })
  }
})
