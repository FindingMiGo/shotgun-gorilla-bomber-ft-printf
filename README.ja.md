# Shotgun Gorilla Bomber — ft_printf

[English](README.md)

> *"Testing shows the presence, not the absence of bugs."*
> — Edsger W. Dijkstra

知らんけど。14万発ぶち込めばだいたいわかる。

他のテスターは賢くやろうとしてる。ゴリラは賢くない。でも全部やる。

---

お前の ft_printf、本当に動いてるか？ フラグ全組み合わせ × 幅 × 精度 × エッジケースを脳死で全部試す。考えない。全部やる。それがゴリラ。

## なにをテストするの

- 指定子: `%d` `%i` `%c` `%s` `%p` `%x` `%X` `%u` `%%`
- フラグ: `#` `0` `+` ` ` `-` の全31組み合わせ + フラグなし
- 幅: (なし), 0, 1, 3, 6, 7, 10, 15
- 精度: (なし), `.`, `.0`, `.1`, `.3`, `.10`, `.15`
- ヤバい値: `INT_MAX`, `INT_MIN`, `LONG_MAX`, `LONG_MIN`, `ULONG_MAX`, `NULL`, NUL文字, 空文字列, 幅50とか100とか, 前後にテキストくっつけたやつ

全部 printf の出力と比較する。一致しなかったら FAIL。以上。

## 使い方

```sh
# ft_printf リポジトリの中にクローンしろ
cd path/to/ft_printf
make
git clone https://github.com/FindingMiGo/shotgun-gorilla-bomber-ft-printf.git
cd shotgun-gorilla-bomber-ft-printf
sh ft_printf_tester.sh
```

こう置け:
```
ft_printf/           # お前の ft_printf
├── ft_printf.h
├── libftprintf.a
├── libft/           # ft_printf.h が libft のヘッダを include しているなら必要
└── shotgun-gorilla-bomber-ft-printf/
    ├── ft_printf_tester.c
    └── ft_printf_tester.sh
```

## どうなるの

全部通ったとき:
```
  Shotgun Gorilla Bomber — exhaustive ft_printf tester

  Results: ALL 146960 PASSED
```

ダメだったとき:
```
  Shotgun Gorilla Bomber — exhaustive ft_printf tester

FAIL %#0x [15]
  out: "0xf" → "0XF"
  ret: 3 → 3

  Results: 146957 passed, 3 failed / 146960 total
```

通ったやつは何も言わない。落ちたやつだけ教えてくれる。ゴリラは優しい。
