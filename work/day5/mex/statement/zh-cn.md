{{ self.title() }}

{{ s('description') }}

有一个长度为n的数组{$a_1,a_2,...,a_n$}。m次询问，每次询问一个区间内最小没有出现过的自然数。

{{ s('input format') }}

{{ self.input_file() }}

第一行n,m。

第二行为n个数。

从第三行开始，每行一个询问l,r。

{{ s('output format') }}

{{ self.output_file() }}

一行一个数，表示每个询问的答案。

{{ s('sample', 1) }}

{{ self.sample_text() }}

{{ s('subtasks') }}

对于100%的数据：1<=n,m<=200000,0<=$a_i$<=$10^9$,1<=l<=r<=n。

对于30%的数据：1<=n,m<=1000。
