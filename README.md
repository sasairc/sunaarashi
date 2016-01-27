sunaarashi
===

[![license](https://img.shields.io/badge/License-WTFPL2-blue.svg?style=flat)](http://www.wtfpl.net/txt/copying/)

![](http://40.media.tumblr.com/533e5826de3f8e87dee1ecc76788834f/tumblr_o1j4khgFQq1u2jamko1_1280.jpg)

擬似乱数でいい感じの模様を作るツール。


## Requirements

* GNU Make
* gcc or clang
* libjpeg


## Install

```shellsession
% make
# make install
```


## Options

* `-q, --quality=[1-100]`	
jpegフォーマットでの圧縮レベルを調整します。デフォルトでは`100`です。
* `-w, --width=PIXEL`	
画像の横幅を指定します。デフォルトでは`640`です。
* `-h, --height=PIXEL`	
画像の高さを指定します。デフォルトでは`480`です。
* `-r, --red=[0-255]`	
乱数での、赤色の最大値を指定します。
* `-g, --green=[0-255]`		
乱数での、緑色の最大値を指定します。
* `-b, --blue=[0-255]`	
乱数での、青色の最大値を指定します。


ちなみに、ヘッダのイメージは`-r 84 -g 128 -b 32 -w 856 -h 512`で生成しました。


## Usage

```shellsession
% sunaarashi -r 96 -g 128 -b 16 -w 1500 -h 500 output.jpg
```


## License

[WTFPL version 2](http://www.wtfpl.net/txt/copying/)


## Author

sasairc (https://github.com/sasairc)
