# Mobita The Crafter

### Tugas Besar IF2210 Pemrograman Berbasis Objek

This repository is a solution of the nobita's problem. This program in this repository is adapted from inventory system and crafting table in minecraft.

## Directory Structure

This repository consists of:

- `config` containing all the config files (items and recipes)
- `tests` containing unit test and end to end sample test (input and answer)
- `src` containing sources code
- `doc` containing Class Diagram and the document

## Running the program

Make sure you are using Linux with C++17. WSL also works if you are using Windows. To install all depedencies, you can run this command:

```shell
sudo apt install make g++
```

To run the program, run below command:

```shell
make run
```

## Running Tests

To run all tests, you have to install Google Test library. To install the depedency, you can run this command:

```shell
sudo apt install libgtest-dev make g++
```

To run tests, run below command:

```shell
make test
```

## Items
- Log (Oak, Spruce, Birch)
- Plank (Oak, Spruce, Birch)
- Stick
- Stone
  - Cobblestone
  - Blackstone
- Iron Ingot
- Iron Nugget
- Diamond
- Tools (Wooden, Stone, Iron, Diamond)
  - Pickaxe
  - Axe
  - Sword 

** New Items **

- Bowl
- Warped Stem
- Warped Plank
- Furnace
- Crafting Table
- Oak Door
- Spruce Door
- Birch Door
- Warped Door
- Wooden/Stone/Iron/Diamond Shovel
- Wooden/Stone/Iron/Diamond Hoe

## Commands
- `EXPORT PATH`: Export inventory to PATH
- `SHOW`: Show current inventory and crafting table
- `CRAFT`: Crafting current state of crafting table
- `MULTICRAFT`: Crafting current state of crafting table all the way to non-recipe state
- `GIVE ITEMNAME ITEMQTY`: Give ITEMQTY of ITEMNAME
- `MOVE SRCID N DESTID1 DESTID2 ... DESTIDN`: Moving N items to the N desired destination, divided equally
- `MULTIMOVE SRCID N DESTID`: Moving N items to one desired destination
- `DISCARD SRCID ITEMQTY`: Delete ITEMQTY items from SRCID
- `USE SRCID`: Use tool item in SRCID
- `HELP`: Show help

## Screenshot
![Main Program](img/main.png "Main Program")

## Authors

We are from 'Tambang Jaya' group (Group number 10) and this is our members:

- Hana Fathiyah - 13520047
- Yohana Golkaria Nainggolan - 13520053
- Firizky Ardiansyah - 13520095
- Andika Naufal Hilmy - 13520098
- Bayu Samudra - 13520128
