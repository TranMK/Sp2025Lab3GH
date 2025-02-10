---
title: "CS2028C Lab 4"
author: ["Ansh Mendiratta", "Khoi Tran", "Thanh Tin"]
date: "2025-02-10"
---

# Lab Writeup
Date: 2/10/2025

Group members:

- Ansh Mendiratta
- Khoi Tran
- Thanh Tin

## class `Show`
- `Show::play()` will be available to derived classes and will be implemented in and call by the derived class (note the `virtual`).
- `Show::details()` will be available with the possibility to be overridden.
- The getters and setters will be available but ideally not overriden.

## class `Movie`
- `Show::play()` will be available and overriden in Movie class, displaying the summary of the user's selected season and episode.
- `Show::details()` will be available and redefined in Movie class, displaying class Show's 2 attributes along with the number of seasons.

## class `TVShow`
- `Show::play()` will be available and overriden in Movie class, displaying the attribute value of the TV Show's rating.
- `Show::details()` will be available and not overriden in Movie class.

Instance scenarios:
Declarations                          Available variables
Show                                  Title, Description, Play(), Details()
Movie                                 Title, Description, Play() of Movie, Details() of Movie
TVShow                                Title, Description, Play() of TV Show, Details() of TV Show
Movie declared as a Show              Title, Description, Play() of Show, Details() of Movie
TVShow declared as a Show             Title, Description, Play() of Show, Details() of TV Show