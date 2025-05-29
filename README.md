# get\_next\_line

![Score](https://img.shields.io/badge/Score-125%2F100-lightgrey) ![C](https://img.shields.io/badge/C-100%25-lightgrey)

> *Read one line at a time from a file descriptor*
> *(a [42 School](https://www.42.fr) project)*

---

## Table of Contents

* [About 📌](#about)
* [Prototype 📄](#prototype)
* [Versions 🔀](#versions)

---

## About 📌

`get_next_line` reads from a file descriptor and returns the next line, including the terminating newline (`\n`), or `NULL` on EOF or error.

---


## Prototype 📄

```c
char *get_next_line(int fd);
```

Include the header:

```c
#include "get_next_line.h"
```

---

## Versions 🔀

* **Pointer version**: under `pointer/` – needs revision.
* **Array version**: under `array/` – delivered and passed via Moulinette.

---

