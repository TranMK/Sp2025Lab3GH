---
title: "CS2028C Lab 5"
author: ["Ansh Mendiratta", "Khoi Tran", "Thanh Tin"]
date: "2025-02-10"
---
# Lab Writeup
Group members:

- Ansh Mendiratta (Wrote main and shelf class implementation)
- Khoi Tran (Wrote template class implementation and code testing)
- Thanh Tin (Wrote game class implementation and code testing)

The objectives and concepts explored in this lab are templates and exceptions. As for their significant in this course and as a career in CS/Engineering, I believe that these concepts are super important, as templates allow you to shorten the time writing functions for multiple data type, similar to how functions shorten the time to write the same block of lines, and exceptions allow you to handle different types of exceptions that might occur in the system, and let you preemptively handle them instead of letting them affect the user experience.

## `shelf` class
Assuming the class is to be a `Stack`,

1. `add_movie`: post-increment `movie_count` and use its old value to index into the array to set the value.
1. `remove_movie`: pre-decrement `movie_count` and use its new value to index into the array to set the value.

Tests prior to error checking:

```image-layout-a
![[Pasted image 20250217151241.png]]
![[Pasted image 20250217151614.png]]
```
![[Pasted image 20250217151644.png]]

Tests after error checking:
```image-layout-a
![[Pasted image 20250217153908.png]]
![[Pasted image 20250217153952.png]]
```

### Trapping the error in `main` versus the calling function
Letting the exception be handled in `main` allows you to handle it however you wish every time it is invoked. If the exception was instead handled in the function, the corresponding `catch` would always run the same code — no matter the situation.