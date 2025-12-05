# PPM Image Viewer

its bad but it does work on my machine.

build command:

```bash
gcc -Wall -Wextra -g -o iv iv.c `sdl2-config --cflags --libs`
```

Run with:

```bash
cat example.ppm | ./iv
```
