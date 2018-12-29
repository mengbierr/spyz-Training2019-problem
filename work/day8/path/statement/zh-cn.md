{{ self.title() }}

{{ s('description') }}

给出一个n个点的树，每条边上有一个权值，一条路径的权值定义为这条路径上所有边的权值异或和，求权值最大的路径的权值。

{{ s('input format') }}

{{ self.input_file() }}

第一行一个正整数n。

接下来n-1行，每行3个正整数u,v,w,表示这条边的两个端点和这条边的权值。

{{ s('output format') }}

{{ self.output_file() }}

输出一个整数，表示答案。

{{ s('sample', 1) }}

{{ self.sample_text() }}

{{ self.title_sample_description() }}

选择1-3这条路径，权值为3^4=7.

{{ s('subtasks') }}

对于30%数据，$n\le 10$。

对于40%数据，$n\le 100$。

对于60%数据，$n\le 1000$。

对于80%数据，$n\le 10000$。

对于100%数据，$n\le 100000$,每条边的权值$\le 2^{31}-1$。