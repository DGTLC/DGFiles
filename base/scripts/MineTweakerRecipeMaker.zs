// File generated by MineTweakerRecipeMaker
//                     READ THIS HEADER BEFORE EDITING ANYTHING
// ================================================================================
//     This file is read and changed by the mod.
//     If you remove/edit any of the markers, IT WILL STOP WORKING!
//     If you want to make manual edits, make a backup of this file!
//     Markers look like this: "//#MARKER something"
//     They indicate where calls should be placed, so that MineTweaker does them in the correct order.
//     Removes come first, then stuff is added.
// ================================================================================
//

// ================================================================================
//#MARKER REMOVE
recipes.remove(<harvestcraft:shippingbin>);
recipes.remove(<harvestcraft:market>);
recipes.remove(<locks:key_blank>);
recipes.remove(<locks:lock_pick>);
recipes.remove(<locks:lock>);
recipes.remove(<harvestcraft:freshwateritem>);

// ================================================================================
//#MARKER REMOVE SHAPELESS

// ================================================================================
//#MARKER REMOVE SHAPED

// ================================================================================
//#MARKER ADD

// ================================================================================
//#MARKER ADD SHAPELESS

// ================================================================================
//#MARKER ADD SHAPED
recipes.addShaped(<locks:lock_pick>, [[null, <ore:nuggetAluminum>, <ore:leather>], [<ore:nuggetAluminum>, <ore:ingotIron>, <ore:nuggetAluminum>], [<ore:stickSteel>, <ore:nuggetAluminum>, null]]);
recipes.addShaped(<locks:lock>, [[<ore:nuggetAluminum>, <ore:ingotIron>, <ore:nuggetAluminum>], [<ore:ingotIron>, <immersiveengineering:metal:21>, <ore:ingotIron>], [<ore:blockIron>, <ore:blockIron>, <ore:blockIron>]]);
recipes.addShaped(<locks:key_blank>, [[null, <ore:ingotIron>, null], [<ore:nuggetLead>, <ore:ingotIron>, <ore:nuggetLead>], [null, <ore:nuggetLead>, null]]);
recipes.addShaped(<cyberware:surgery>, [[<ore:blockIron>, <ore:ingotIron>, <ore:blockIron>], [<ore:blockRedstone>, <immersiveengineering:metal_decoration0:4>, <minecraft:observer>], [<ore:blockIron>, <immersiveengineering:metal_decoration0:3>, <ore:blockIron>]]);

