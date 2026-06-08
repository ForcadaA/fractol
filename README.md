_This project has been created as part of the 42 curriculum by aforcada_

# Description

`fractol` builds fractal visuals with zooming.

It supports:
- **Mandelbrot set** (`m`)
- **Douaby set** (`d`)  
- **Julia set** (`j`) with custom complex seed

# Instructions

- Run `make`
```bash
make
```

- Explore Mandelbrot set
```bash
./fractol m
```

- Explore Douaby set
```bash
./fractol d
```

- Explore julia set
```bash
./fractol j 0.285 0.01
```

- Type `ESC` or close window to terminate program.


## Requirements

- **MinilibX** (the 42 version)
- **X11** / **XQuartz** (on macOS)
- **make**, **gcc** / **clang**

# Resources
- [minilibx](https://harm-smits.github.io/42docs/libs/minilibx)
- [X](https://tronche.com/gui/x/xlib/)
- [Simon's fractol](https://github.com/simon231442/RANK02/tree/main/fract-ol)
- AI was used to help produce the README
