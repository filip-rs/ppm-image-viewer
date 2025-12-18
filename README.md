# PPM Image Viewer

VERY basic image viewer written from basics in C with SDL2.
This is not made to be useful at all but the application does work (hyprland on arch).

build command:

```bash
gcc -Wall -Wextra -g -o iv iv.c `sdl2-config --cflags --libs`
```

Run with:

```bash
cat example.ppm | ./iv
```
