# Corewar
This project was the last part of [Hive Helsinki](https://www.hive.fi/en/) ([School 42](https://42.fr/en/homepage/)) core studies (*old curriculum*) for our team:

[André Backman](https://github.com/andrelmbackman), [Matias Jokela](https://github.com/matiasjokela), [Pyry-Peetri Piironen](https://github.com/pyrypiironen) and [Teppo Pölönen](https://github.com/tpolonen).

### Table of Contents

1. [Description](##description)
2. [Project overview](##project-overview)
3. [The Assembler](##the-assembler)
4. [The Virtual Machine](##the-virtual-machine)
5. [The Champion](##the-champion)



## Description

Corewar is the implementation of 1984 created programming game [Core war](https://en.wikipedia.org/wiki/Core_War).

> <em> In Core war, two or more battle programs (called "warriors") compete for control of a virtual computer.
These battle programs are written in an abstract assembly language called Redcode. The standards for the language and the virtual machine
were initially set by  the International Core Wars Society (ICWS), but later standards were determined by community consensus. </em>

## Project overview

The project has three mandatory parts:
- The Assembler
- The Virtual Machine
- The Champion

The full assignment [PDF](https://github.com/pyrypiironen/Corewar/blob/main/corewar.pdf).

## The Assembler

*Coming soon . . . .*

## The Virtual Machine

The VM executable is called `corewar` and it will be compiled by running `make`.

The VM allocates a memory area called the arena, places the champions in the arena, and executes the gameplay.

Before the game, the VM will introduce the contestants and after the game, it declares the winner.

### Usage

`./corewar <flags> <champ_1.cor> <champ_2.cor> <...>`

### Flags

| Flag | Description |
| :---:| :--- |
| `-a <N>` | Show cycles and operations. Dump memory after N cycles. |
| `-b` | Execute lld statement with the same bug as the original Corewar. Also, make aff statement invisible. Using this flag makes the program replicate the original Core war in all cases. |
| `-c <N>` | Dump data from carriages after N cycles. |
| `-d <N>` | Dump memory in the same form as the original Corewar after N cycles. |
| `-dump <N>` | Dump memory on the form asked on the pdf after N cycles. |
| `-n <N>` | Set the number of the next player. |


## The Champion

The last part of the project was to write our own champion. The point was pretty much just to do a valid champion and we ended up creating
HansMoleman no more than 15 minutes.
<details>
<summary>Click here to see code.</summary>
	
```
.name "Hans"
.comment "Go Springfield!"

st r1, 2050
live %0
fork %999
live %0
fork %999
live %0
fork %999
live %0
fork %999
live %0
fork %999
live %0
fork %999
live %0
fork %999
live %0
fork %999
live %0
fork %999
live %0
fork %999
live %0
fork %999
live %0
fork %999
live %0
fork %999
live %0
fork %999
```
</details>
<details>
<summary>Click here to see original Hans Moleman.</summary>
	<p>
<img src="https://user-images.githubusercontent.com/93189576/226182249-a9eba58c-1eb8-4e3d-946e-e54ddb8c172d.png" alt="1">
	</p>
</details>
