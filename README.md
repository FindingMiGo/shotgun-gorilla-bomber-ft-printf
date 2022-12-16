# Shotgun Gorilla Bomber — ft_printf

[日本語](README.ja.md)

> *"Testing shows the presence, not the absence of bugs."*
> — Edsger W. Dijkstra

Whatever. 146,000 rounds should be enough to figure it out.

Other testers try to be smart. Gorilla is not smart. But gorilla tests everything.

---

Does your ft_printf actually work? This tester brute-forces every flag combination × width × precision × edge case against the real printf. No thinking. Just fire. That's gorilla.

## What it tests

- Specifiers: `%d` `%i` `%c` `%s` `%p` `%x` `%X` `%u` `%%`
- Flags: all 31 combinations of `#` `0` `+` ` ` `-` + no flags
- Width: (none), 0, 1, 3, 6, 7, 10, 15
- Precision: (none), `.`, `.0`, `.1`, `.3`, `.10`, `.15`
- Nasty values: `INT_MAX`, `INT_MIN`, `LONG_MAX`, `LONG_MIN`, `ULONG_MAX`, `NULL`, NUL char, empty string, width 50/100, text around specifiers

Everything is compared against printf. Mismatch = FAIL. That's it.

## Usage

```sh
# Clone inside your ft_printf repository
cd path/to/ft_printf
make
git clone https://github.com/FindingMiGo/shotgun-gorilla-bomber-ft-printf.git
cd shotgun-gorilla-bomber-ft-printf
sh ft_printf_tester.sh
```

Directory layout:
```
ft_printf/           # your ft_printf
├── ft_printf.h
├── libftprintf.a
├── libft/           # if your ft_printf.h includes libft headers
└── shotgun-gorilla-bomber-ft-printf/
    ├── ft_printf_tester.c
    └── ft_printf_tester.sh
```

## Output

All passed:
```
  Shotgun Gorilla Bomber — exhaustive ft_printf tester

  Results: ALL 146960 PASSED
```

Something broke:
```
  Shotgun Gorilla Bomber — exhaustive ft_printf tester

FAIL %#0x [15]
  out: "0xf" → "0XF"
  ret: 3 → 3

  Results: 146957 passed, 3 failed / 146960 total
```

Only failures are printed. Gorilla is kind.
