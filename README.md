# Presentation Tool

Takahashi based slide render and presentation software.

## Table Of Contents

- [Table Of Contets](#table-of-contents)
- [Features](#features)
  - [Syntax](#syntax)
  - [Images](#images)
  - [Fonts](#fonts)
  - [Renderers](#renderers)
  - [Progress](#progress)
- [Contributing](#contributing)
- [Prior Art](#prior-art)
- [License](#license)

## Features

### Syntax

See [example](./example) for a complete example file.

- Each paragraph is one slide.
- The content of a slide is denoted by a tab (`\t`).
- The first character (if not a tab (`\t`)) controls the markup of that slide:
    - `#`  -> Heading.
    - `=`  -> Centered (default if empty).
    - `<`  -> Left aligned.
    - `>`  -> Right aligned.
    - `@`  -> Content until first whitespace denotes an img-path to be included
              in the slide.
    - `-`  -> Content is a bullet point.
    - `\`` -> Content is monospaced.
    - `.`  -> Space (content on line is ignored).
- If the paragraph only contains a `.` an empty slide is produced.

See [example.zm](./example.zm) for a reference.

### Images

This program supports the following file types:

- TODO: .jpg
- TODO: .png
- TODO: .gif

### Fonts

TODO: How to support different fonts?

### Renderers

- TODO: Default renderer (Vulkan/OpenGL)?
- TODO: How to export to pdf?

### Progress

TODO: How to customize progress bar?

### Themes

TODO: How to customize themes?

- Two color themes:
  - Foreground: #ffffff by default
  - Background: #000000 by default

## Contributing

I appreciate any contributions. Make sure that you are descriptive enough to
reproduce your issue and kind enough when interacting with anybody in regards
to this project.

:bow:

## Prior Art

Naturally this project didn't came into existance in a vacuum:

- [suckless/sent][suckless/sent] - This project is the most simple approach to
    a presentation software. It lacks certain features which would make it
    usable in the daily business.
- [tajpure/vortex][tajpure/vortex] - Electron-based Markdown presentation tool.
    A lot of extraneous features, that are really handy but not very useful for
    simple, powerful and pregnant presentation.
- [Impress][libreoffice/impress] - The pinacle of graphical presentation tools.
    Arguably too bloated and convoluted.

## License

Copyright © 2018 Karl Fleischmann

This software is distributed under the terms of the Apache License Version 2.0
(Apache-2.0). For details see [LICENSE](./LICENSE).


[suckless/sent]: https://tools.suckless.org/sent/
[tajpure/vortex]: https://github.com/tajpure/vortex
[libreoffice/impress]: https://www.libreoffice.org/discover/impress/
