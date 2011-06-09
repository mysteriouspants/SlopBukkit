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

## CS116

I suppose some would call this course C++ II or something. It was fun. We used Bjarne Stroustrup's textbook _Practical Programming using C++_ (or some similar title - it's been a little while). The overall course was great. By using the FLTK library we were able to build simple GUI systems and stuff. Nothing quite so advanced as what I've done in Java or Cocoa, but it was neat to draw stuff to the screen using C++ for once.

### AnalogClock

This was the darn funniest thing ever. The assignment was to draw a clock to a window using FLTK. Now, I was fully aware of `FLClock`, which is an FLTK routine to draw an analog clock. However, I, in my paranoia, believed this to be _cheating_. And I do not cheat. Except at _Metro 2033_ and _Prototype_. So I spent a lot of time and effort figuring out some trig maths to figure all of this out. Professor Topham loved it, but had to admit that he was just expecting `FLClock` since the main point of the exercise was to update the screen periodically instead of lock-step with the FLTK user input main loop.

The code is awesome though.

### Book

If anyone can understand what was going on here, that'd be nice. As far as I'm concerned, it's just more boring uninventive example classes.

### Ch 14 Drill - Inheritance

This was a fairly simple exercise in which we made a class which would draw a smily face. Following this we extended this class to make a smily face with a hat.

### Ch14Asgn

Some kind of exercise involving more inheritance and utilising a controller pattern.

### Chapter 4 Drill

I think this is some kind of conversion tool. Isn't it fun to look at old school code and try to reverse engineer what it was that you were doing?

### Chapter 10 Drill

Vectors, points, and `IOStream`, so it's anybody's guess what's going on here.

### Chapter 12 Drill

This one loads images.

### Chapter 13 Asgn

This one was pretty difficult because it involved drawing an arrow. Determining the proper place to stick the arrowhead and how to rotate it, etc, is pretty darn hard. Some supergenius in class got us an equation to use for that purpose, and it seems to work fairly well. Now that I've taken more Calculus (and ostensibly been molested by more trig) I'm sure I could do pretty well by myself now, but for the time, it was a Godsend. This appears to try and draw the reference image from http://cdn.fsdev.net/filegraph.png which is amazingly still hanging around on my CDN.

This seems redundant to my `File Diagram` work in CS116, so I'm not sure what I have two copies for. But they're different. Judging by the naming and the code, I made `File Diagram` first, then got angry and the ugly code, so I made `Chapter 13 Asgn` which looks cleaner due to the `vector`s and automatic drawing. At this point I'm just speculating; I have really no clue how to explain any of this.

### Chapter 14 Drill - Virtual Functions

Virtual functions and pure-virtual functions are the pits. After having dealt with these little buggers, I was very appreciative of the simple elegance of Objective-C.

### Chapter 15 Asgn

I knew that I had built something which graphed stuff before, though I couldn't for the life of me remember when or where or why. It's good to know that I've at least found it again.

### Chapter 16 Asgn

This is the first time we got input from the FLTK GUI system as far as I can tell.

### Chapter 19 Asgn

Data structure programming is fun, and here we got to make a linked list.

### Date

Some kind of custom date class.

### File Diagram

This one was pretty difficult because it involved drawing an arrow. Determining the proper place to stick the arrowhead and how to rotate it, etc, is pretty darn hard. Some supergenius in class got us an equation to use for that purpose, and it seems to work fairly well. Now that I've taken more Calculus (and ostensibly been molested by more trig) I'm sure I could do pretty well by myself now, but for the time, it was a Godsend. This appears to try and draw the reference image from http://cdn.fsdev.net/filegraph.png which is amazingly still hanging around on my CDN.

This seems redundant to my `File Diagram` work in CS116, so I'm not sure what I have two copies for. But they're different. Judging by the naming and the code, I made `File Diagram` first, then got angry and the ugly code, so I made `Chapter 13 Asgn` which looks cleaner due to the `vector`s and automatic drawing. At this point I'm just speculating; I have really no clue how to explain any of this.

### LinkedList0

Maybe this was a first stab at Chapter 17's assignment?

### LinkedList1

OK, now I know this isn't me. I don't do extra credit... do I?

### Multifile

I think this was just getting stuff to load across files properly.

### Name Pairs

Also known as a Map or Dictionary, this is very advanced technology that only second-semester C++ students can butcher in an implementation-specific manner.

### Namespace Fun

Namespaces yoh, they be all up in yo business! In reality I don't have a clue what the point of this assignment was.

### Order of Evaluation

Is it wrong of me to read this code and only be able to wonder what the compiler intrinsic for the `XCHNG` opcode is?

### PG165

A truly horrifying number of simple source files relating to a bunch of exercises from the mythical 165th page. Some of these answers are actually kind of witty.

### Sieve of Eroatosthenes

The amazing unpronounceable means of finding prime numbers. I have a much better version in assembler.

### Temp Calc

To me this was actually really cool, and it's one of the four or so assignments from this course I really remember years later. It showed how to use STL's `iostream` library for the purpose of object serialization. I'm a meticulous nut when it comes to serialization, just look at any of my `NSCoder` code. This was actually really cool to me.

### Week Map

Not sure what this is supposed to do. Perhaps it will make sense to me someday?

## CS118

Yay x86 assembler work, all done using MASM!

## CS172

Some files from my J2EE Servlets and JSPs class.

## MGTwitterEngine

This might be the version of MGTwitterEngine that I modified to handle the fetching of blocked users. Or it might not be. I honestly do not know.

## whirlpool

Personal favorite hash algorithm. Not sure where I got this code, but I've been carting it around for a few years or so if the file times are to be believed.

## check-logger

This is a streamlined data-entry tool written in Digital Mars D using the `tango` library and `dwt`, back before you could mix Tango and Phobos. It should build using my old Easy D project releases, which are available at http://cdn.fsdev.net/easy-d

## source-scope

A (really) old Java project from high school. It walks a source tree of Java files and counts some statistics that might have been meaningful to me at some point in time. I was thinking that someday I might come back to it, however, I think it's usefulness is basically nil at this point. It is something of a relic or curiosity, though.