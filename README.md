# ryu

Print floating-point numbers to strings in their shortest, most accurate
representation.

This implementation consists mostly of the code taken directly from the
original work in the [ulfjack/ryu](https://github.com/ulfjack/ryu) project,
with the additon of a new `ryu_print` function, that provides a little extra
safety and convenience. 

Also, this library is a single self-contained C file for easily adding to
exising projects.

## Usage

```C
// ryu_print converts a double into a string representation that is copied
// into the provided C string buffer.
//
// Returns the number of characters, not including the null-terminator, needed
// to store the double into the C string buffer.
// If the returned length is greater than nbytes-1, then only a parital copy
// occurred.
// 
// The fmt argument can be 'f' for full decimal or 'e' for scientific notation.
size_t ryu_print(double d, char fmt, char *dst, size_t nbytes)
```

## Example

```C
char buf[32];
size_t n = ryu_print(-112.89123883, 'f', buf, sizeof(buf));
if (n >= sizeof(buf)) {
	// Buffer is too small to.
}
printf("%s\n", buf);

// Output: -112.89123883
```

## License

Code from the original [ulfjack/ryu](https://github.com/ulfjack/ryu) project:

```
Copyright 2018 Ulf Adams

The contents of this file may be used under the terms of the Apache License,
Version 2.0.

   (See accompanying file LICENSE-Apache or copy at
    http://www.apache.org/licenses/LICENSE-2.0)

Alternatively, the contents of this file may be used under the terms of
the Boost Software License, Version 1.0.
   (See accompanying file LICENSE-Boost or copy at
    https://www.boost.org/LICENSE_1_0.txt)

Unless required by applicable law or agreed to in writing, this software
is distributed on an "AS IS" BASIS, WITHOUT WARRANTIES OR CONDITIONS OF ANY
KIND, either express or implied.
```

The `ryu_print` function:

```
Copyright (c) 2023 Josh Baker

Permission is hereby granted, free of charge, to any person obtaining a copy of
this software and associated documentation files (the "Software"), to deal in
the Software without restriction, including without limitation the rights to
use, copy, modify, merge, publish, distribute, sublicense, and/or sell copies of
the Software, and to permit persons to whom the Software is furnished to do so,
subject to the following conditions:

The above copyright notice and this permission notice shall be included in all
copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY, FITNESS
FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR
COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER
IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN
CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.
```
