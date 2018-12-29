{{ self.title() }}

{{ s('description') }}

给定$n\times p$和$p\times m$的矩阵$A$和$B$，求$A\times B$。

{{ s('input format') }}

{{ self.input_file() }}

第一行三个正整数$n$、$p$、$m$，表示矩阵的长宽。

之后的$n$行，每行$p$个整数，表示矩阵$A$。

之后的$p$行，每行$m$个整数，表示矩阵$B$。

{{ s('output format') }}

{{ self.output_file() }}

输出$n$行，每行$m$个整数，表示矩阵$A \times B$，每个数模 $10 ^ 9 + 7$输出。

{{ s('sample', 1) }}

{{ self.sample_text() }}

{{ s('subtasks') }}

$1\le n,p,m\le 500,-10^9\le A_{i,j},B_{i,j}\le 10^9$