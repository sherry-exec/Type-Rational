# Rational Class - C++

Why I Started This Project:
May 2015, I was making my semester project, which was a command-line matrix manipulator application written in c++.
It was simple and easy, when i was done in a month. I was testing my program, imagine viewing 10x10 matrix with no
empty-line between rows, that real numbers (some having 2 or 5 digits after decimal and some dont) i was so annoyed
viewing that, also i cannot manage proper tabs between elements.
Therefore i decided to write a very very simple library for this application, using real numbers (also integers)
in fractional representation (p/q).

Challenges:
There are so many free and good libraries for managing rational numbers in c++, But i always had problem using them,
i dont know why, either because they donot provide a friendly function set or to setup them in my IDE gives me headache.
So i came up with my own libray, which i intended to be very user-friendly, but i also take care algorithms and
performance.

An Idea:
While i was building, i got an idea hey this is able to convert real numbers (double) into fraction format (0.5 -> 1/2),
also it can parse string into a fractional number ("5/2" -> 5/2), and back to both of them.
(i am not mentioning integers because they are obviously supported).
So i was wondering an object of this type can replace double and integer, so should we bother using double or interger,
because this can replace both and do with both.

Why I Open-Sourced It and Did'nt Published It:
If a person says he is smart, then surely he is'nt, similarly i cannot say that my library is complete and perfect.
(although it is complete from my perspective) BUT this is a global community and i am not the perfect here, nor i am
the best coder, thinker and solver therefore with a group of people colaborating we can make it more better in every way.
I know the developers here are master and point out many things in this code which i want, also to learn (because it is forever)..

Technical:
An object of this type (Rational)
has overloaded almost every operator with Integer and Doubles.
At first i overloaded it with only objects of its own type but i did that for 2 reasons:
1. It can interact with double and integer, so using objects of type rational for whole program will do it.
2. If someone want to use this in a program written earlier, they will easily do it ease.

Some Important Functions to Motivate:
Simplification of a Fraction.
Conversion from Double to Fraction Format.
To String. (i started this for command-line but encapsulating numbeer in a string "p/q" can be useful for GUI)

Help to Make it Better and Global..
