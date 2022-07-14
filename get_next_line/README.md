# get_next_line

### Prototype
char *get_next_line(int fd);  

### Description
ファイルディスクリプタから読み込んだ1行を返す関数  
Write a function which returns a line read from a file descriptor  

### Conditions
1. 関数 get_next_line をループで呼び出すと、ファイルディスクリプタで利用できるテキストを一度に一行ずつ、最後まで読み込むことができるようになります。  
Calling your function get_next_line in a loop will then allow you to read the text available on the file descriptor one line at a time until the end of it.  
2. この関数は、ちょうど読み込まれた行を返す必要があります。他に読むべきものがない場合、あるいはエラーが発生した場合は NULL を返さなければなりません。  
Your function should return the line that has just been read. If there is nothing else to read or if an error has ocurred it should return NULL.  
3. ファイルから読み込むときと、標準入力から読み込むときに、関数の動作するようにする  
Make sure that your function behaves well when it reads from a file and when it reads from the standard input.  

4. libftはこのプロジェクトでは許可されていません。このプロジェクトでは、get_next_line_utils.c ファイルを追加する必要があります。この関数には、get_next_line が動作するために必要な関数が含まれています。  
libft is not allowed for this project. You must add a get_next_line_utils.c file which will contain the functions that are needed for your get_next_line to work.  

5. プログラムは、flag -D BUFFER_SIZE=xx でコンパイルする必要があり、これは get_next_line の read 呼び出しのバッファサイズとして使用されます。この値は、あなたの評価者と moulinette によって変更されます。  
Your program must compile with the flag -D BUFFER_SIZE=xx which will be used as the buffer size for the read calls in your get_next_line. This value will be modified by your evaluators and by the moulinette.  

6. The program will be compiled in this way:  
gcc -Wall -Wextra -Werror -D BUFFER_SIZE=42 <files>.c.  

7. ヘッダーファイル get_next_line.h には、少なくとも関数 get_next_line のプロトタイプが必要です。  
In the header file get_next_line.h you must have at least the prototype of the function get_next_line.  

8. lseek は許可された関数ではありません。ファイルの読み込みは一度だけでなければならない。  
→ファイルポインタをstartに戻してはならないという意味  
lseek is not an allowed function. File reading must be done only once.  

9. 2回の呼び出しの間に、最初のfdからすべてを読み込む前に同じファイル記述子が別のファイルに切り替わる場合、get_next_lineの動作は未定義であると考える。  
We consider that get_next_line has undefined behavior if, between two calls, the same file descriptor switches to a different file before reading everything from the first fd  

10. 最後に、get_next_lineはバイナリファイルから読み込む場合、未定義の動作をすることを考慮します。しかし、もし望むなら、この挙動を首尾一貫したものにすることができます。  
Finally we consider that get_next_line has undefined behavior when reading from a binary file. However, if you wish, you can make this behavior coherent.  

11. グローバル変数禁止  
Global variables are forbidden  

12. ファイルの最後まで到達して'\n'がない場合を除いて、必ず読み終えた行の後に'\n'を付けて返してください。  
Important: You should always return the line that has been read followed by a ’\n’ unless you have reach end of file and the is no ’\n’.  

### BONUS
get_next_lineというプロジェクトはストレートで、ボーナスの余地はほとんどありませんが、皆さんはきっと想像力が豊かなのでしょう。必須パートをクリアした方は、ぜひこのボーナスパートをクリアして、さらに先へ進んでください。ただし、ボーナスはありません。必須項目が完璧でない場合は、考慮されません。このパートでは、_bonus.[ch]で終わる3つの必須ファイルをすべて提出すること。  

The project get_next_line is straightforward and leaves very little room for bonuses, but we are sure that you have a lot of imagination. If you have aced the mandatory part, then by all means, complete this bonus part to go further. Just to be clear, no bonuses
will be taken into consideration if the mandatory part isn’t perfect. Turn-in all 3 mandatory files ending by _bonus.[c\h] for this part.  

1. get_next_lineを1つのスタティック変数で継承すること。  
To succeed get_next_line with a single static variable.  

2. 複数のファイルディスクリプタをget_next_lineで管理できるようにする。例えば、ファイルディスクリプタ 3, 4, 5 が読み込み可能な場合、 get_next_line を 3, 4 で一度ずつ、3 でもう一度、5 で一度ずつ呼び出すと、それぞれの ディスクリプタで読み込みスレッドを失うことなく、読み込める。  
To be able to manage multiple file descriptors with your get_next_line. For example, if the file descriptors 3, 4 and 5 are accessible for reading, then you can call get_next_line once on 3, once on 4, once again on 3 then once on 5 etc. without losing the reading thread on each of the descriptors.  
