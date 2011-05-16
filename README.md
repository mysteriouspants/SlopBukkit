# Slop Bukkit (Public)

This is old code. Really old code. Stuff from college and even a project dating back to high-school. The kind of code which makes you think "wow, that was kind of nifty when I wrote it! I want to save this!"

As the title implies, there is a private slop bukkit of mine which has some stuff which I don't want to release to the public. Mainly screenshots of old games I'm totally going to write new engines for. Someday. Anyways, that's all in the private repo because of perceived copyright issues.

## DuffsDevice.d

A short and simple D code file demonstrating how to unroll loops using a Duff's Device technique. Duff's Device is a C-language trick which overlays a jump table on top of a partially unrolled loop. The overall effect is that you can stream instructions to out-of-order executors on the chip without sacrificing the precision of loop iterations.

So far (to my knowledge, which is limited) Duff's Device works in C, C++, Objective-C, Java, and Digital Mars D.

## CS102 (Introduction to C++ Programming)

I took this course at Ohlone College in Fremont, CA. It was designed to familiarize students with the basics of the C++ language, while conveniently skipping C's procedural quirks. Note that these assignments are copyright by me - turning them in for credit yourself is expressly prohibited. Either way, I think they're using a different textbook now.

### Chapter 1 Assignment

Simple program which prompts for user input and sanitizes it as much as possible leveraging default STL `iostream` objects. Considering how little code I had to write, it worked out really really well.

### Chapter 2 Assignment

A slightly more complex program which uses a C++ `struct` (note that it's a C++ `struct` - it would only become a C `struct` if we wrapped it in `extern "C" {}`) and then overloads an `iostream` operator to make it easier to prompt for the `struct` as an input.

### Chapter 3 Assignment

This one actually took me a little while if I remember correctly. I'm used to C's `stdio.h` library for output formatting because it's so gosh-darn terse. Beating C++'s `iostream` object over the head with a monkey wrench to get it to output things properly took quite a bit of work. Not to mention that it behaves differently on different platforms. And, at least on the version of GCC/Xcode I was using at the time, it seemed to behave differently in `gdb` versus `Terminal.app` and also differently in `release` versus `debug` mode! Eventually I got it working decently enough though. I think this one also uses File I/O. Judging by the echo statement, I used one of my oldest tricks to generate the test file without having to bundle it.

### Chapter 4 Assignment

Ugly ASCII-art shipping cost calculator. I think I was considering using `ncurses` for this, but when I looked at the `curses` API... well, I figured it wasn't worth the time. I think the purpose of this assignment was to introduce array programming.

### Chapter 5 Assignment

Not quite sure what was being taught here. I learned that not all hotels have a thirteenth floor. The spec sheet says we should have been learning to use loops... not really sure how that got put off to chapter 5 though.

### Chapter 6 Assignment

Some kind of point of sale tool. I think I got bored so I split it up into multiple files.

### Chapter 7 Assignment

ASCII-art theater seating chart program.

### Chapter 9 Assignment

Some kind of string manipulation exercise.

## CS118

Yay x86 assembler work! All done using MASM.

## CS172

Some files from my J2EE Servlets and JSPs class.

## MGTwitterEngine

This might be the version of MGTwitterEngine that I modified to handle the fetching of blocked users. Or it might not be. I honestly do not know.

## whirlpool

Personal favorite hash algorithm. Not sure where I got this code, but I've been carting it around for a few years or so if the file times are to be believed.

## check-logger

This is a streamlined data-entry tool written in Digital Mars D using the `tango` library and `dwt`, back before you could mix Tango and Phobos. It should build using my old Easy D project releases, which are available at http://cdn.fsdev.net/easy-d.

## source-scope

A (really) old Java project from high school. It walks a source tree of Java files and counts some statistics that might have been meaningful to me at some point in time. I was thinking that someday I might come back to it, however, I think it's usefulness is basically nil at this point. It is something of a relic or curiosity, though.