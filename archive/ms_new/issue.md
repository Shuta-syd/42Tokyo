# issue

1. 空白の扱い方が不安定
例)
	$ echo "Hello World"', I'm 42' -> Hello World, I'm 42
	$ echo "Hello World"          ', I'm 42' -> Hello World○, I'm 42
空白が間に1個以上含まれている場合は○の部分に空白が1個出力される
//追記 一番最後に回しても問題はないかも

2. execve()の第二引数argvの形
例)
	$ echo "This is $USER" 'Hello $USER'
上記のコマンドがきた場合argvは{[This is $USER] [ ] [Hello $USER]}になるのか？
→てことは空白でsplit?

3. t_lexで1文字ずつのtokenにわける意味が不安定
