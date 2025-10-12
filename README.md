# My Keyboard Layout

First things first, big thanks to :
- [Empress Abyss](https://github.com/empressabyss), author of the [Nordrassil](https://github.com/empressabyss/nordrassil) layout.
- [Urob](https://github.com/urob), author of the ZMK modules I'm using and of a really good example of a [keymap](https://github.com/urob/zmk-config) that heavily inspired mine.
- [Manna Harbour](https://github.com/manna-harbour), author of the [Miryoku](https://github.com/manna-harbour/miryoku) layout, which inspired the way I handle my layers and showed me just how much you can pack in a keymap.
- [Getreuer](https://github.com/getreuer), which has an amazing [write-up](https://getreuer.info/posts/keyboards/symbol-layer/index.html) on designing a symbol layer and [choosing a layout](https://getreuer.info/posts/keyboards/alt-layouts/index.html).
- [Caksoylar](https://github.com/caksoylar), author of [keymap-drawer](https://github.com/caksoylar/keymap-drawer), the utility I used to generate the visuals.
- [Foostan](https://github.com/foostan/crkbd/commits?author=foostan), the author of the Corne, which inspired the keyboard I actually bought :
- The Chocofi, based on the Corne, designed by [Pashutk](https://github.com/pashutk/chocofi/commits?author=pashutk).
- The [ZMK](https://github.com/zmkfirmware/zmk) project and it's contributors, for making it possible to have such awesome, custom keyboard firmware.
- And more people I surely forgot, I'm amazed at how awesome QMK and ZMK features have become in the last few years, makes me not want to buy a locked down keyboard ever again!

### Overview 

<img src="draw\base_keymap.svg">
<img src="draw\combos_keymap.svg">

After I bought my keyboard, I looked at layouts and keymaps for days, I landed on the requirement of trying a thumb alpha layout (might as well go for broke if I'm moving away from QWERTY).

I looked at [Hands Down Gold](https://sites.google.com/alanreiser.com/handsdown/home/hands-down-neu#h.1cdqya5986v5) and [Night](https://luminespire.github.io/night/home.html), great layouts, but I completely fell in love with the concept of Arcane keys from [Nordrassil](https://github.com/empressabyss/nordrassil), so I ended up with it's abyssal variant, with a few mod morphs allowing me to move Z back into the main alpha grid.

Other functions are then located on 6 additional layers : Numbers, Functions, Navigation, Symbols, Accents (Je suis Québécois, il me faut mes accents français!) which rely on my [Autohotkey config](https://github.com/Nathanix321/autohotkey-config).

### Modules

Here are the modules I used :
- [zmk-adaptive-keys](https://github.com/urob/zmk-adaptive-key/)
- [zmk-auto-layer](https://github.com/urob/zmk-auto-layer)
- [zmk-helpers](https://github.com/urob/zmk-helpers)
- [zmk-tri-state](https://github.com/urob/zmk-tri-state)

All by [Urob](https://github.com/urob)!

### Mod Morphs, Macros And Smarter Modifiers
Mod morphs :
- Dot shifted into colon.
- Comma shifted into semicolon.
- Question mark shifted into exlamation mark.

I also made space for 4 macros, their use is up to you!

Finally I made use of caps-word, and num-word.

### Arcane Keys
[Nordrassil](https://github.com/empressabyss/nordrassil) implements what [Empress Abyss](https://github.com/empressabyss) calls Arcane keys, which are basically souped-up magic keys. Their function depends on the last key you pressed. 

Rule of thumb : same side arcane key trigger is a repeat (except for T and #), opposite side arcane key trigger is for something else. Logic is inversed for T and right completes with 'MENT'. Left completes # with 'DEFINE', right completes # with 'INCLUDE'. Here's the full table : 

| Previous key | Opposite hand | Previous key | Opposite hand |
|--------------|---------------|--------------|---------------|
| 'A'          | 'ND '         | 'O'          | 'I'           |
| 'B'          | 'ECAUSE '     | 'P'          | 'RETTY'       |
| 'C'          | 'K'           | 'Q'          | 'UEEN'        |
| 'D'          | 'CD'          | 'R'          | 'M'           |
| 'E'          | 'U'           | 'S'          | 'K'           |
| 'F'          | 'OR'          | 'U'          | 'E'           |
| 'G'          | 'ENERAL'      | 'V'          |               |
| 'H'          |               | 'W'          | 'HICH'        |
| 'I'          | 'ON'          | 'X'          |               |
| 'J'          | 'UST'         | 'Y'          | 'EAH'         |
| 'K'          |               | 'Z'          |               |
| 'L'          | 'K'           | 'SPACE'      | 'THE '        |
| 'M'          | 'ENT'         | '.'          | '/'           |
| 'N'          | 'ION'         | ','          | ' BUT '       |

I have also borrowed the adaptive H from [Hands-Down Gold](https://sites.google.com/alanreiser.com/handsdown/home/hands-down-neu#h.ze4kq734zl5w), which solves the 'AU', 'EO', 'UA', 'OE' and 'RN' SFBs.

### Number Layer
<img src="draw\num_keymap.svg">

Tapping the num-word key toggles the num layer until the number is finished, holding momentarily switched to the number layer.

### Function Layer
<img src="draw\fun_keymap.svg">

### Navigation Layer
<img src="draw\nav_keymap.svg">

### Mouse Layer
<img src="draw\mouse_keymap.svg">

The mouse layer is analogous to the navigation layer, and is accessed with the smart-mouse combo. Mouse layer stays activated until you hit the combo again or hit an  empty key.

### Symbol Layer 
<img src="draw\sym_keymap.svg">

### Accent Layer
<img src="draw\acc_keymap.svg">

Requires the use of my [Autohotkey config](https://github.com/Nathanix321/autohotkey-config).
