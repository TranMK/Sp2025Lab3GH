---

title: "CS2028C Lab 5"

author: ["Ansh Mendiratta", "Khoi Tran", "Thanh Tin"]

date: "2025-02-10"

---

# Lab Writeup

Group members:

  

- Ansh Mendiratta (Wrote main and shelf class implementation) (33%)

- Khoi Tran (Wrote template class implementation and code testing) (33%)

- Thanh Tin (Wrote game class implementation and code testing) (33%)

  

The objectives and concepts explored in this lab are templates and exceptions. As for their significance in this course and as a career in CS/Engineering, I believe that these concepts are super important, as templates allow you to shorten the time writing functions for multiple data types, and exceptions allow you to handle different types of exceptions that might occur in the system, and let you preemptively handle them instead of letting them affect the user experience.

  

## `shelf` class

Assuming the class is to be a `Stack`,

  

1. `add_movie`: post-increment `movie_count` and use its old value to index into the array to set the value.

2. `remove_movie`: pre-decrement `movie_count` and use its new value to index into the array to set the value.

  

Tests prior to error checking:

|![[Pasted image 20250222205535.png\|200]]|![[Pasted image 20250222205601.png\|200]]|
|-|-
![[Pasted image 20250222205615.png\|300]]
Tests after error checking:

![[Pasted image 20250223102929.png\|500]]
![[Pasted image 20250223103010.png\|300]]
### Trapping the error in `main` versus the calling function

Letting the exception be handled in `main` allows you to handle it however you wish every time it is invoked. If the exception was instead handled in the function, the corresponding `catch` would always run the same code — no matter the situation.

# Output of Template Test
![[Pasted image 20250223110235.png]]
Using a function/class template over making one for each data type saves time and potential discrepancies between them, since all you need to consider is making sure the operations used within the template.