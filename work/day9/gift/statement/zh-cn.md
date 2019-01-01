{{ self.title() }}

{{ s('background') }}

简单的题目，既是礼物，也是毒药。

{{ s('description') }}

xhl设计了一道简单的题目，准备作为gift送给大家。

平面上有$n$个点，$a_1,a_2,...,a_n$其中$a_1$和$a_2$,$a_2$和$a_3$，...$a_i$和$a_{i+1}$，...$a_{n}$和$a_{1}$间有边相连。现在xhl想知道它们围成的多边形的面积。

{{ s('input format') }}

{{ self.input_file() }}

第一行一个正整数$n$。

接下来$n$行，每行两个数,$x_{a_i}$,$y_{a_i}$表示第$i$个点的坐标。

{{ s('output format') }}

{{ self.output_file() }}

输出一个小数，表示答案，保留三位小数。

{{ s('sample', 1) }}

{{ self.sample_text() }}

{{ s('subtasks') }}

对于30%数据，$n=3$。

对于50%数据，$n\le 4$。

对于100%数据，$3\le n\le 100000,-1000\le x_i,y_i\le 1000$。