# Brainfuck-interpreter
Brainfuck interpreter written by c++

#使い方
* interpreter 

  コンパイル

    `g++ -o brainfuck-interpreter brainfuck-interpreter.cpp`

  brainfuckプログラムの実行

    `brainfuck-interpreter <input file>`

* Text_to_BF*

  テキストファイル(ASCII文字)から、そのテキストを表示するbrainfuckプログラムを作成

 コンパイル

    `g++ -o Text_to_BF Text_to_BF.cpp`

  実行（output file name で指定した名前のファイルをカレントディレクトリに作成）

    `Text_to_BF <input file> <output file name>`
  
  ループを使わない単純な実装なのでファイルサイズが無駄に大きくなります。
