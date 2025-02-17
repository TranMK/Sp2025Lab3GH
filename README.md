---
title: "CS2028C Lab 5"
author: ["Ansh Mendiratta", "Khoi Tran", "Thanh Tin"]
date: "2025-02-10"
---
# Lab Writeup
Group members:

- Ansh Mendiratta
- Khoi Tran
- Thanh Tin

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