# fract-ol

One of the first graphical projects at 42 school, fract-ol generates beautiful fractals. This project uses the school's graphical library, MiniLibX.

# Status

Awaiting evaluation.

# Usage

---

Note that this project was tested on Linux only. It may run on MacOS with small adjustments to the Makefile, as described in hsmits and jvan-sni's [42 Docs](https://harm-smits.github.io/42docs/libs/minilibx/getting_started.html).

---

## Installing and Compiling Fract-ol

Clone the repository, including the embedded MiniLibX repository:
```shell
git clone https://github.com/mcombeau/fract-ol.git && cd fract-ol && git submodule init && git submodule update
```

You will now be in the correct directory for compilation. Compile with ```make```. Fract-ol should now be ready!

## Executing Fract-ol

At execution time, you must specify a fractal to display. You may also provide other optional parameters:

```shell
./fractol <type> <options>
```

Types are :
* ```M```, ```m```, or ```1```: Mandelbrot fractal
* ```J```, ```j```, or ```2```: Julia fractal
* ```B```, ```b```, or ```3```: Burning Ship fractal
* ```T```, ```t```, or ```4```: Tricorn fractal
* ```X```, ```x```, or ```5```: Mandelbox fractal

For the Julia fractal set (and only this set), two additional parameters can be specified as calculation values. These represent a complex number that will change the shape of the Julia fractal. They must be fractional numbers between 2.0 and -2.0. For example:

```shell
./fractol J 0.285 -0.01
```

Additionally, you may specify a hexadecimal color for the fractal display:

```shell
./fractol M 00CCFF
```

Please note that for the Julia set, the color option will only be available after specifying calculation values:

```shell
./fractol J -0.4 0.6 65CD87
```

## Fract-ol Controls

While Fractol is running, the following set of controls are available:

<table>
  <tr><td><strong>Controls</strong></td><td><strong>Action</strong></td></tr>
  <tr><td>WASD or arrow keys</td><td>Move</td></tr>
  <tr><td>-, + or scroll wheel</td><td>Zoom in and out</td></tr>
  <tr><td>Spacebar</td><td>Change color scheme</td></tr>
  <tr><td>Left Click</td><td>Shift Julia set [Julia only]</td></tr>
  <tr><td>1, 2, 3,  4, or 5</td><td>Switch fractals</td></tr>
  <tr><td>ESC or close window</td><td>Quit fract-ol</td></tr>
</table>

---
Made by mcombeau: mcombeau@student.42.fr | LinkedIn: [mcombeau](https://www.linkedin.com/in/mia-combeau-86653420b/) | Website: [codequoi.com](https://www.codequoi.com)
