{{ self.title() }}

{{ s('description') }}

xhl最近迷上了全排列，他经常会将1~n的全排列写出来，并统计它们逆序对的个数。但他的耐心是有限的，于是他找到了你，希望知道n个数组成的所有排列中，逆序对数为k的序列个数。答案可能很大，只需输出答案除以1000000007的余数。

对于排列p，逆序对数即满足i<j且p[i]>p[j]的二元组（i，j）数量。

{{ s('input format') }}

{{ self.input_file() }}

一行两个正整数n，k。

{{ s('output format') }}

{{ self.output_file() }}

一行，表示答案。

{{ s('sample', 1) }}

{{ self.sample_text() }}

{{ s('sample', 2) }}

{{ self.sample_text() }}

{{ s('sample', 3) }}

{{ self.sample_text() }}


{{ s('subtasks') }}

对于20%数据，n,k<=5.

对于40%数据，n,k<=20.

对于60%数据，n,k<=100.

对于80%数据，n,k<=6000.

对于另20%数据，n<=100000,k<=50.

对于0%的数据，n=100000，k=100000