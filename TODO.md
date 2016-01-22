# PTMUD-next

## Things to do

I need to find the old TODO documents and add to this.

### General things to do

* Split `interpreter.c` into multiple files
    1. One for the actual command interpreter
    2. One for all other players states
* Scripting?
    * Lua?
    * Python?
    * DG-scripts?
    * DG-scripts *enhanced*?
    * Home-made?
* On-Line Creation?
  This is very low priority, and might not happen at all.

### Library files

* ASCII player files
    * Including saving objects (inside player file)
* ASCII mail files
* ASCII rent files

### Players

* New skills
    * Multiple attacks
* Increased levels
    * Including more immortal levels?
* Instead of using levels as a way to set limits or privileges for immortals, use flags

### Mobiles

* Multiple attacks
* Spell-casting defined in mob file
* Assign special function in mob file

### Items

* Super-cursed items that drain hp/mana/move
* Super-blessed items that gives hp/mana/move

### Rooms

* Rooms that drains (or gives) hp/mana/move
* Extended doors
    * Custom messages when passing through a door
    * Different descriptions when opening, closing, locking or unlocking a door
    * Door special functions
    * Anti-class doors

### Shops

### Zones

### Areas

New area system, where each area can contain multiple zones.
Virtual numbers should be relative to the area and not global.

Area files should list all other file (obj/mob/wld/shp/zon) files that should be loaded.

### Internal structures

* Better split for character structures
    * Separate player/mobile structures
    * If a character structure have a mobile structure pointer, the it's an NPC. Better check than the flag that is used now.
* Better split of structures that are saved and not saved
    * Player structures
    * Object structure (for player items and rent files)
 
### The world

* Reorganize the world library files in areas.
* Make use of new features in the server
