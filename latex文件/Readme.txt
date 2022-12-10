来自jzchen的补充
1. 建议装textstudio编辑(是编辑, 不是编译), 因为标记比较明显. 但不能用它编译
2. 需要装texlive, 可以在线装也可以下载镜像装, 镜像有4G (https://mirrors.sustech.edu.cn/CTAN/systems/texlive/Images/texlive.iso)
3. 不建议用Texworks编辑,  界面不友好, 标记不明显, 搜索不方便; 也不建议用Texworks编译, 因为它不能生成参考文献
4. 解决了不能直接生成并引用参考文献的问题
5. 减小了目录中标题到页码的指引线(虚线点之间)的间距
6. 模仿了北邮学位论文的资源
7. 调整了封面论文题目的宽度, 一行能放下不多于19个汉字. 建议题目字数少于19
8. 正文行距从1.62调整到1.5倍
9. 补充了更多的类型的bib格式
10. 章末尾增加了\newpage强行分页
11. 采用了另外一种插图方式
12. 增加了公式示例
13. 增加了makethesis.bat与makethesis文件

编译方法:
1. 在当前文件夹的资源管理器的地址栏中输入cmd再回车
2. 输入makethesis并回车

advices from jzchen:
插图建议用visio画, 然后打印成pdf, 再用adobe pdf自带的裁剪工具裁剪, 再在文中插入该pdf文件. 则生成与插入的为矢量图效果好.

关于版本回退:
版本回退可以用git revert命令, 例如:
git revert HEAD     // 撤销前一次 commit 
git revert HEAD^   //撤销前前一次 commit
版本回退还可以用git reset命令, 例如:
git reset HEAD       // 撤销前一次 commit
git revert是用一次新的commit来回滚之前的commit, git reset是直接删除指定的commit
