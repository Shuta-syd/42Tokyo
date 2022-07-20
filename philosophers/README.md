# Philosophers

## Overview

ここでは、この課題を成功させるために知っておくべきことを紹介します。

Here are the things you need to know if you want to succeed this assignment:

- 一人または複数の哲学者が円卓に座っている。
テーブルの真ん中にはスパゲッティの入った大きなボウルがある。
One or more philosophers sit at a round table.
There is a large bowl of spaghetti in the middle of the table.
- 哲学者たちは、食べたり、考えたり、眠ったりしている。食べている間は考えず、眠らず、考えている間は食べず、眠らず、そしてもちろん、眠っている間は食べず、考えず、である。
 The philosophers alternatively eat, think, or sleep. While they are eating, they are not thinking nor sleeping; while thinking, they are not eating nor sleeping; and, of course, while sleeping, they are not eating nor thinking.
- テーブルの上にはフォークもあります。哲学者の数だけフォークがあるのです。
 There are also forks on the table. There are as many forks as philosophers.
- スパゲッティをフォーク1本で食べるのはとても不便なので、哲学者は右手と左手に1本ずつフォークを持って食べます。
Because serving and eating spaghetti with only one fork is very inconvenient, a
philosopher takes their right and their left forks to eat, one in each hand.
- 哲学者は食事を終えると、フォークをテーブルに戻し、眠り始める。目が覚めると、再び思考を開始する。哲学者が餓死すると、シミュレーションは終了する。
When a philosopher has finished eating, they put their forks back on the table and
start sleeping. Once awake, they start thinking again. The simulation stops when a philosopher dies of starvation.
- すべての哲学者は食べる必要があり、決して飢えてはならない。
Every philosopher needs to eat and should never starve.
- 哲学者同士は話をしない。
Philosophers don’t speak with each other.
- 哲学者は、他の哲学者が死のうとしているのかどうかを知らない。
Philosophers don’t know if another philosopher is about to die.
- 哲学者は死ぬのを避けるべきと言う必要はない!
 No need to say that philosophers should avoid dying!

## Global rules

あなたは、必須パート用のプログラムと、ボーナスパート用のプログラム（ボーナスパートを行うことにした場合）を作成する必要があります。どちらも以下のルールに従わなければならない。

You have to write a program for the mandatory part and another one for the bonus part
(if you decide to do the bonus part). They both have to comply with the following rules:

- グローバル変数は使用禁止！
Global variables are forbidden!
- あなたの（複数の）プログラムは、以下の引数を取る必要があります。
    
    number_of_philosophers time_to_die time_to_eat time_to_sleep [number_of_times_each_philosopher_must_eat]
    
    - number_of_philosophers:  哲学者の数、また、フォークの数
    - time_to_die (in milliseconds): もし哲学者が最後の食事の開始またはシミュレーションの開始からtime_to_dieミリ秒の間に食べ始めなかった場合、彼らは死にます。
    - time_to_eat (in milliseconds): 哲学者が食事をするのにかかる時間。その間、2本のフォークを持つ必要がある。
    - time_to_sleep (in milliseconds): 哲学者が眠りにつく時間。
    - number_of_times_each_philosopher_must_eat (optional argument): すべての哲学者が少なくともnumber_of_times_each_philosopher_must_eat 回以上食べた場合, シミュレーションは停止します. 指定しない場合は、哲学者が死亡した時点でシミュレーションを終了します。
    
- 各哲学者は1からnumber_of_philosophersまでの番号を持っています。
Each philosopher has a number ranging from 1 to number_of_philosophers.
- 哲学者番号1は哲学者番号number_of_philosophersの隣に座っている。
他の哲学者番号Nは、哲学者番号N - 1と哲学者番号N + 1の間に位置する。
Philosopher number 1 sits next to philosopher number number_of_philosophers.
Any other philosopher number N sits between philosopher number N - 1 and philosopher number N + 1.

About the logs of your program:

- 哲学者の状態変化は、以下のような書式にする必要があります。
    - timestamp_in_ms X has taken a fork
    - timestamp_in_ms X is eating
    - timestamp_in_ms X is sleeping
    - timestamp_in_ms X is thinking
    - timestamp_in_ms X died
    
    timestamp_in_ms をミリ秒単位の現在のタイムスタンプに、X を哲学者番号に置き換えてください。
    Replace timestamp_in_ms with the current timestamp in milliseconds and X with the philosopher number.
    

- 表示される状態メッセージは、他のメッセージと混在してはならない。
A displayed state message should not be mixed up with another message.
- 哲学者が死んだというメッセージは、その哲学者が実際に死んでから10ミリ秒以内に表示されなければならない。
A message announcing a philosopher died should be displayed no more than 10 ms
after the actual death of the philosopher.
- 繰り返しますが、哲学者は死なないようにすべきです。
Again, philosophers should avoid dying!

## Mandatory part

| Program name | philo |
| --- | --- |
| Turn in files | Makefile, *.h, *.c, in directory philo/ |
| Arguments | number_of_philosophers time_to_die time_to_eat time_to_sleep [number_of_times_each_philosopher_must_eat] |
| External functs. | memset, printf, malloc, free, write, usleep, gettimeofday, pthread_create, pthread_detach, pthread_join, pthread_mutex_init, pthread_mutex_destroy, pthread_mutex_lock, pthread_mutex_unlock |
| Libft authorized | No |
| Description | Philosophers with threads and mutexes |

必須部分の具体的なルールは

The specific rules for the mandatory part are:

- 各哲学者はスレッドであるべきである
Each philosopher should be a thread.
- 各哲学者のペアの間には、1つのフォークが存在する。したがって、哲学者が複数いる場合、各哲学者は左側にフォークを持ち、右側にフォークを持つ。哲学者が一人しかいない場合、テーブルの上にはフォークは一本だけであるべき
There is one fork between each pair of philosophers. Therefore, if there are several
philosophers, each philosopher has a fork on their left side and a fork on their right
side. If there is only one philosopher, there should be only one fork on the table.
- 哲学者のフォークの重複を防ぐため、フォークの状態をそれぞれ排他制御で保護する必要があります。
To prevent philosophers from duplicating forks, you should protect the forks state with a mutex for each of them.

## Bonus part

| Program name | philo_bonus |
| --- | --- |
| Turn in files | Makefiles, *.h, *.c, in directory philo_bonus |
| Aruguments | number_of_philosophers time_to_die time_to_eat time_to_sleep [number_of_times_each_philosopher_must_eat] |
| External functs. | memset, printf, malloc, free, write, fork, kill, exit, usleep, gettimeofday, pthread_create, pthread_detach, pthread_join, waitpid, sem_open, sem_close, sem_post, sem_wait, sem_unlink |
| Libft authorized | No |
| Description | Philosophers with processes and semaphores |

ボーナスパートのプログラムは、必須プログラムと同じ引数を取ります。 また、グローバルルールの章の要件に従わなければならない。

- すべてのフォークはテーブルの真ん中に置かれる。
- これらのフォークはメモリ上に状態を持たないが、利用可能なフォークの数はセマフォで表現される。
- 各哲学者はプロセスであるべきである。しかし、メイン・プロセスは哲学者であってはならない。

___参考資料

[https://docs.google.com/presentation/d/12-lAykLu-RVACE1gI2aP-uEYZoOaeeFVYGh8W4ttTNw/edit#slide=id.gd4524b1be8_0_459](https://docs.google.com/presentation/d/12-lAykLu-RVACE1gI2aP-uEYZoOaeeFVYGh8W4ttTNw/edit#slide=id.gd4524b1be8_0_459)
