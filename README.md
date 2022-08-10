# fract-ol

<p align="center">
  <img src="https://github.com/mcombeau/mcombeau/blob/main/42_badges/fract-ole.png" alt="Fract'ol fract-ol 42 project badge"/>
</p>

One of the first graphical projects at 42 school, fract-ol generates beautiful fractals from the complex numbers of an iterative mathematical construct. A fractal is a fragmented geometrical figure that infinitely repeats itself at smaller scales. This project uses the school's graphical library, MiniLibX.

![Fract-ol mono-colored Mandelbrot by mcombeau](https://github.com/mcombeau/fract-ol/blob/main/screenshots/Fractol-Mandelbrot.png)

---

:us: Read my article in English about this project: [Fract’ol: generating fractals in C](https://www.codequoi.com/en/fract-ol-generating-fractals-in-c/)

:fr: Lire mon article en français sur ce projet :  [Fract’ol : générer des fractales en C](https://www.codequoi.com/fract-ol-generer-des-fractales-en-c/)

---

# Status

Finished: 22/04/2022.

Grade: 125%.

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
  <tr><td><kbd>&nbsp;W&nbsp;</kbd><kbd>&nbsp;A&nbsp;</kbd><kbd>&nbsp;S&nbsp;</kbd><kbd>&nbsp;D&nbsp;</kbd> or <kbd>&nbsp;▲&nbsp;</kbd><kbd>&nbsp;◄&nbsp;</kbd><kbd>&nbsp;▼&nbsp;</kbd><kbd>&nbsp;►&nbsp;</kbd></td><td>Move</td></tr>
  <tr><td><kbd>&nbsp;-&nbsp;</kbd>, <kbd>&nbsp;+&nbsp;</kbd> or <kbd>&nbsp;scroll wheel&nbsp;</kbd></td><td>Zoom in and out</td></tr>
  <tr><td><kbd>&nbsp;space&nbsp;</kbd></td><td>Change color scheme</td></tr>
  <tr><td><kbd>&nbsp;left click&nbsp;</kbd></td><td>Shift Julia set [Julia only]</td></tr>
  <tr><td><kbd>&nbsp;1&nbsp;</kbd>, <kbd>&nbsp;2&nbsp;</kbd>, <kbd>&nbsp;3&nbsp;</kbd>, <kbd>&nbsp;4&nbsp;</kbd>, or <kbd>&nbsp;5&nbsp;</kbd></td><td>Switch fractals</td></tr>
  <tr><td><kbd>&nbsp;esc&nbsp;</kbd> or close window</td><td>Quit fract-ol</td></tr>
</table>

# Screenshots

## Mandelbrot set

![Fract-ol purple and yellow striped Mandelbrot by mcombeau](https://github.com/mcombeau/fract-ol/blob/main/screenshots/Fractol-Mandelbrot-2.png)
![Fract-ol red bllue and green striped Mandelbrot by mcombeau](https://github.com/mcombeau/fract-ol/blob/main/screenshots/Fractol-Mandelbrot-3.png)
![Fract-ol sun crest purple Mandelbrot by mcombeau](https://github.com/mcombeau/fract-ol/blob/main/screenshots/Fractol-Mandelbrot-4.png)

## Julia set

![Fract-ol purple green and yellow Julia by mcombeau](https://github.com/mcombeau/fract-ol/blob/main/screenshots/Fractol-Julia.png)
![Fract-ol red swirl Julia by mcombeau](https://github.com/mcombeau/fract-ol/blob/main/screenshots/Fractol-Julia-2.png)
![Fract-ol blue snowflake Julia by mcombeau](https://github.com/mcombeau/fract-ol/blob/main/screenshots/Fractol-Julia-3.png)

## Burning ship set

![Fract-ol golden burning ship by mcombeau](https://github.com/mcombeau/fract-ol/blob/main/screenshots/Fractol-Burning-Ship.png)

## Mandelbox set

![Fract-ol brown tribal Mandelbox by mcombeau](https://github.com/mcombeau/fract-ol/blob/main/screenshots/Fractol-Mandelbox.png)

---
Made by mcombeau: mcombeau@student.42.fr | LinkedIn: [mcombeau](https://www.linkedin.com/in/mia-combeau-86653420b/) | Website: [codequoi.com](https://www.codequoi.com)
