{{ self.title() }}

{{ s('description') }}

是题目名字吸引你进来的。

设计数据结构支持:

1 x  若x不存在,插入x

2 x  若x存在,删除x

3    输出当前最小值,若不存在输出-1

4    输出当前最大值,若不存在输出-1

5 x  输出x的前驱,若不存在输出-1

6 x  输出x的后继,若不存在输出-1

7 x  若x存在,输出1,否则输出-1

{{ s('input format') }}

{{ self.input_file() }}

第一行给出n,m 表示出现数的范围和操作个数

接下来m行给出操作

{{ s('output format') }}

{{ self.output_file() }}

对于每个询问，输出答案。

{{ s('sample', 1) }}

{{ self.sample_text() }}

{{ s('sample', 2) }}

{{ self.sample_file() }}

{{ s('subtasks') }}

对于100%数据，n<=$10^6$,m<=$2*10^6$,0<=x<n

{{ s('hint') }}

**本题数据没有梯度，没有合适的做法请不要盲目尝试**（虽然这题并不难）