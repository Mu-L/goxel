/* Goxel 3D voxels editor
 *
 * copyright (c) 2018 Guillaume Chereau <guillaume@noctua-software.com>
 *
 * Goxel is free software: you can redistribute it and/or modify it under the
 * terms of the GNU General Public License as published by the Free Software
 * Foundation, either version 3 of the License, or (at your option) any later
 * version.

 * Goxel is distributed in the hope that it will be useful, but WITHOUT ANY
 * WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS
 * FOR A PARTICULAR PURPOSE.  See the GNU General Public License for more
 * details.

 * You should have received a copy of the GNU General Public License along with
 * goxel.  If not, see <http://www.gnu.org/licenses/>.
 */

/* This file is autogenerated by tools/create_assets.py */

{.path = "data/other/povray_template.pov", .size = 748, .data =
    "// Generated from goxel {{version}}\n"
    "// https://github.com/guillaumechereau/goxel\n"
    "\n"
    "{{#camera}}\n"
    "camera {\n"
    "    perspective\n"
    "    right x*{{width}}/{{height}}\n"
    "    direction <0, 0, -1>\n"
    "    angle {{angle}}\n"
    "    transform {\n"
    "        matrix {{modelview}}\n"
    "        inverse\n"
    "    }\n"
    "}\n"
    "{{/camera}}\n"
    "\n"
    "#declare Voxel = box {<-0.5, -0.5, -0.5>, <0.5, 0.5, 0.5>}\n"
    "#macro Vox(Pos, Color)\n"
    "    object {\n"
    "        Voxel\n"
    "        translate Pos\n"
    "        translate <0.5, 0.5, 0.5>\n"
    "        texture { pigment {color rgb Color / 255} }\n"
    "    }\n"
    "#end\n"
    "\n"
    "{{#light}}\n"
    "global_settings { ambient_light rgb<1, 1, 1> * {{ambient}} }\n"
    "light_source {\n"
    "    <0, 0, 1024> color rgb <2, 2, 2>\n"
    "    parallel\n"
    "    point_at {{point_at}}\n"
    "}\n"
    "{{/light}}\n"
    "\n"
    "union {\n"
    "{{#voxels}}\n"
    "    Vox({{pos}}, {{color}})\n"
    "{{/voxels}}\n"
    "}\n"
    ""
},



