# born2beroot

### Introduction

このプロジェクトは、仮想化の素晴らしい世界を紹介することを目的としています。特定の指示のもと、VirtualBoxで最初のマシンを作成します。そして、このプロジェクトの最後には、厳密なルールを実行しながら、あなた自身のオペレーティングシステムをセットアップすることができるようになります。

This project aims to introduce you to the wonderful world of virtualization.
You will create your first machine in VirtualBox under specific instructions. Then, at the end of this project, you will be able to set up your own operating system while implementing strict rules.

### General guidelines

- VirtualBox（VirtualBoxが使えない場合はUTM）の利用が必須です。
    
    The use of VirtualBox (or UTM if you can’t use VirtualBox) is mandatory.
    
- リポジトリのルートにsignature.txtを提出するだけです。その中にあなたのマシンの仮想ディスクの署名を貼り付ける必要があります。詳しくは Submission and peer-evaluation をご覧ください
    
     You only have to turn in a signature.txt file at the root of your repository. You must paste in it the signature of your machine’s virtual disk. Go to Submission and peer-evaluation for more information
    

### Mandatory part

このプロジェクトは、特定のルールに従って最初のサーバーを立ち上げてもらうというものです。

This project consists of having you set up your first server by following specific rules.

> サーバーを立ち上げることなので、最低限のサービスをインストールすることになります。このため、ここではグラフィカルなインターフェースは役に立ちません。したがって、X.orgやその他の同等のグラフィックサーバーをインストールすることは禁じられています。さもなければ、あなたの成績は0点となります。
> 

Since it is a matter of setting up a server, you will install the
minimum of services. For this reason, a graphical interface is of no
use here. It is therefore forbidden to install [X.org](http://x.org/) or any other
equivalent graphics server. Otherwise, your grade will be 0.

OSはDebianの最新安定版(testing/unstableなし)かCentOSの最新安定版のどちらかを選択する必要があります。初めてシステム管理を行う場合は、Debianを強くお勧めします。

You must choose as an operating system either the latest stable version of Debian (no testing/unstable), or the latest stable version of CentOS. Debian is highly recommended if you are new to system administration.

CentOSのセットアップはかなり複雑です。そのため、KDumpを設定する必要はありません。ただし、SELinuxは起動時に起動しておく必要があり、その設定もプロジェクトのニーズに合わせて変更する必要があります。DebianのAppArmorもスタートアップで起動しておく必要があります。

Setting up CentOS is quite complex. Therefore, you don’t have to set up KDump. However, SELinux must be running at startup and its configuration has to be adapted for the project’s needs. AppArmor for Debian must be running at startup too

LVMを使用して、少なくとも2つの暗号化パーティションを作成する必要があります。以下は予想されるパーティション分割の例です。

You must create at least 2 encrypted partitions using LVM. Below is an example of the expected partitioning:

防衛の間、あなたは選んだオペレーティングシステムについていくつかの質問をされるでしょう。例えば、aptitudeとaptの違いや、SELinuxやAppArmorが何なのかを知っておく必要があります。要するに、自分が使っているものを理解することです。

During the defense, you will be asked a few questions about the operating system you chose. For instance, you should know the differences between aptitude and apt, or what SELinux or AppArmor is. In short, understand what you use!

SSH サービスは、ポート 4242 のみで実行されます。セキュリティ上の理由から、rootでSSHを使用して接続することはできないようにする必要があります。

A SSH service will be running on port 4242 only. For security reasons, it must not be possible to connect using SSH as root.

SSHの使用は、新しいアカウントを設定することによって、防衛中にテストされます。アカウントでテストされます。そのため、その仕組みを理解しておく必要があります。

The use of SSH will be tested during the defense by setting up a new account. You must therefore understand how it works.

UFWファイアウォールをOSに設定し、4242番ポートのみを開放する必要があります。4242番ポートを開放してください。

You have to configure your operating system with the UFW firewall and thus leave only port 4242 open.

仮想マシンを起動する際には、ファイアウォールが有効である必要があります。CentOSの場合、デフォルトのファイアウォールの代わりにUFWを使用する必要があります。インストールするには、DNFが必要です。

Your firewall must be active when you launch your virtual machine.
For CentOS, you have to use UFW instead of the default firewall. To
install it, you will probably need DNF.

- 仮想マシンのホスト名には、42で終わるログイン名（例：wil42）を使用する必要があります。評価中にこのホスト名を変更する必要があります。
    
    The hostname of your virtual machine must be your login ending with 42 (e.g.,wil42). You will have to modify this hostname during your evaluation.
    
- 強力なパスワードポリシーを導入する必要があります。
    
     You have to implement a strong password policy.
    
- sudoのインストールと設定は、厳密なルールに従って行う必要があります。
    
    You have to install and configure sudo following strict rules.
    
- ルートユーザーの他に、ユーザー名としてあなたのログインを持つユーザーが存在する必要があります。
    
    In addition to the root user, a user with your login as username has to be present.
    
- このユーザーはuser42とsudoグループに所属している必要があります。
    
    This user has to belong to the user42 and sudo groups.
    

防衛の際には、新しいユーザーを作成し、それをグループに割り当てる必要があります。

During the defense, you will have to create a new user and assign it to a group.

強力なパスワードポリシーを設定するためには、以下の要件に準拠する必要があります。

- パスワードの有効期限は30日です
    
    Your password has to expire every 30 days
    
- パスワードの変更までに許容される最短日数は、2日に設定されます。
    
    The minimum number of days allowed before the modification of a password will be set to 2.
    
- パスワードの有効期限が切れる7日前に警告メッセージを表示する必要があります。
    
    The user has to receive a warning message 7 days before their password expires.
    
- パスワードは10文字以上でなければなりません。大文字と数字が含まれている必要があります。また、同じ文字が3つ以上連続して含まれていてはいけません。
    
    Your password must be at least 10 characters long. It must contain an uppercase letter and a number. Also, it must not contain more than 3 consecutive identical characters.
    
- パスワードにユーザー名を含んではならない。
    
    The password must not include the name of the user.
    
- rootのパスワードには、以下のルールは適用されません。パスワードには、以前のパスワードに含まれていない文字が少なくとも7文字含まれていなければなりません。
    
    The following rule does not apply to the root password: The password must have at least 7 characters that are not part of the former password.
    
- もちろん、rootパスワードはこのポリシーに従わなければなりません。
    
    Of course, your root password has to comply with this policy
    

> 設定ファイルの作成後、rootアカウントを含む、仮想マシン上に存在するすべてのアカウントのパスワードを変更する必要があります。
> 

After setting up your configuration files, you will have to change all the passwords of the accounts present on the virtual machine, including the root account.

sudoグループに強力な設定を行うには、以下の要件を満たす必要があります。

To set up a strong configuration for your sudo group, you have to comply with the following requirements:

- sudo使用時にパスワード間違いによるエラーが発生した場合、任意のカスタムメッセージを表示する必要があります。
    
    A custom message of your choice has to be displayed if an error due to a wrong password occurs when using sudo.
    

- sudo を使用する各アクションは、入力と出力の両方をアーカイブする必要があります。ログファイルは /var/log/sudo/ フォルダに保存されなければなりません。
    
    Each action using sudo has to be archived, both inputs and outputs. The log file has to be saved in the /var/log/sudo/ folder.l
    

- セキュリティ上の理由から、TTYモードは有効にしておく必要があります
    
    The TTY mode has to be enabled for security reasons
    
- また、セキュリティ上の理由から、sudoが使用できるパスを制限する必要があります。
/usr/local/sbin:/usr/local/bin:/usr/sbin:/usr/bin:/sbin:/bin:/snap/bin

最後に、monitoring.shという簡単なスクリプトを作成する必要があります。これは、bashで開発する必要があります。

Finally, you have to create a simple script called [monitoring.sh](http://monitoring.sh/). It must be developed in bash.

サーバー起動時に、スクリプトは10分ごとにいくつかの情報（以下にリストアップ）をすべての端末に表示します（壁を見てみてください）。バナーは任意です。エラーは表示される

At server startup, the script will display some information (listed below) on all terminals every 10 minutes (take a look at wall). The banner is optional. No error must
be visible

スクリプトは常に以下の情報を表示できるようにする必要があります。

Your script must always be able to display the following information:

- オペレーティングシステムのアーキテクチャとカーネルバージョン。
    
    The architecture of your operating system and its kernel version.
    
- 物理プロセッサーの数
    
    The number of physical processors.
    
- 仮想プロセッサの数
    
    The number of virtual processors.
    
- サーバー上で現在利用可能な RAM とその使用率（単位：パーセント）
    
    The current available RAM on your server and its utilization rate as a percentage.
    
- サーバー上の現在利用可能なメモリとその使用率（%）
    
    The current available memory on your server and its utilization rate as a percentage.
    
- プロセッサの現在の使用率（%）
    
    The current utilization rate of your processors as a percentage.
    
- 最後に再起動した日付と時刻
    
    The date and time of the last reboot.
    
- LVMがアクティブかどうか
    
    Whether LVM is active or not.
    
- アクティブな接続数
    
    The number of active connections.
    
- サーバーを使用しているユーザー数
    
    The number of users using the server.
    
- サーバーのIPv4アドレスとそのMAC（Media Access Control）アドレス
    
    The IPv4 address of your server and its MAC (Media Access Control) address.
    
- sudo プログラムで実行されたコマンドの数
    
    The number of commands executed with the sudo program
    

答弁では、このスクリプトがどのように動作するかを説明することが求められます。また、それを修正せずに中断する必要があります。cronを覗いてみてください。

During the defense, you will be asked to explain how this script works. You will also have to interrupt it without modifying it. Take a look at cron.

以下は、被写体の条件の一部を確認するために使用できる2つのコマンドです。

Below are two commands you can use to check some of the subject’s requirements:

### Bonus Part

ボーナスリスト

- パーティションを正しく設定することで、以下のような構造になります。

Bonus list:
• Set up partitions correctly so you get a structure similar to the one below:

![スクリーンショット 2022-04-21 13.37.21.png](Born2beroot%208f5cba13c0ca4b8c909a5eb9792a1358/%E3%82%B9%E3%82%AF%E3%83%AA%E3%83%BC%E3%83%B3%E3%82%B7%E3%83%A7%E3%83%83%E3%83%88_2022-04-21_13.37.21.png)

- Lighttpd、MariaDB、PHPのサービスを利用して、機能的なWordPressウェブサイトをセットアップしてください。
    
    Set up a functional WordPress website with the following services: lighttpd, MariaDB, and PHP.
    
- あなたが便利だと思う好きなサービスを設定してください（NGINX / Apache2は除く！）NGINX / Apache2は除く！）防衛の間、あなたは自分の選択を正当化する必要があります
    
    Set up a service of your choice that you think is useful (NGINX / Apache2 excluded!). During the defense, you will have to justify your choice.
    

ボーナス・パートを完成させるために、あなたは追加のサービスを設定する可能性があります。この場合、あなたのニーズに合わせて、より多くのポートを開くことができます。もちろん、UFWのルールはそれに応じて適応させなければなりません。

To complete the bonus part, you have the possibility to set up extra services. In this case, you may open more ports to suit your needs. Of course, the UFW rules has to be adapted accordingly.

ボーナスパーツは、必須パーツがPERFECTである場合にのみ査定されます。パーフェクトとは、必須パートが統合的に行われ、誤動作することなく動作することを意味します。必須条件をすべてクリアしていない場合、ボーナスパーツの評価は一切行われません。

The bonus part will only be assessed if the mandatory part is PERFECT. Perfect means the mandatory part has been integrally done and works without malfunctioning. If you have not passed ALL the mandatory requirements, your bonus part will not be evaluated at all.

Git リポジトリのルートに signature.txt ファイルを置くだけです。その中に、あなたのマシンの仮想ディスクの署名を貼り付けなければなりません。この署名を得るには、まずデフォルトのインストールフォルダを開く必要があります（VMが保存されているフォルダです）。

次に、仮想マシンの「.vdi」ファイル（UTMユーザーの場合は「.qcow2」）から署名をsha1フォーマットで取得します。以下は、centos_serv.vdiファイルに対する4つのコマンド例です。

最初の評価後、仮想マシンの署名が変更されることがありますので、ご注意ください。この問題を解決するには、仮想マシンを複製するか、状態を保存を使用することができます。

Please note that your virtual machine’s signature may be altered after your first evaluation. To solve this problem, you can duplicate your virtual machine or use save state.

> もちろん、Gitリポジトリに仮想マシンを投入することは禁じ手です。ディフェンスでは、signature.txt の署名と、あなたの仮想マシンの署名を比較します。もし両者が同一でない場合、あなたの成績は0点となります。
> 

It is of course FORBIDDEN to turn in your virtual machine in your Git repository. During the defense, the signature of the signature.txt file will be compared with the one of your virtual machine. If the
two of them are not identical, your grade will be 0.

### 参考資料

[https://eng-entrance.com/linux-partition#i-4](https://eng-entrance.com/linux-partition#i-4)
