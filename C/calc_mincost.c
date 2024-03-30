#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>

int calc_mincost(int (*d_vec)[6], int s, int d) {

	int min_cost = 0;
	int temp = 0;

	if ((s == d) || (s == d-1)) {
		printf("\ncost from %u -> %u = %u \n", s, d, d_vec[s][d]);
		return d_vec[s][d];
	}

	min_cost = d_vec[s][d];
	for (int i = s+1; i<d; i++) {
		temp = calc_mincost(d_vec,s,i) + calc_mincost(d_vec,i,d);
		if (temp < min_cost) {
			min_cost = temp;
		}
		printf("\n Min cost from %u -> %u = %u \n", s, d, min_cost);
		return min_cost;
	}
}

int main() {

	int distance_vector[6][6] = {{0,10,20,30,40,500},{-1,0,40,50,70,80},{-1,-1,0,90,100,30},{-1,-1,-1,0,80,30},{-1,-1,-1,-1,0,90},{-1,-1,-1,-1,-1,0}};

	printf("\nMinimum cost = %u\n", calc_mincost(distance_vector,0,5));

	return 1;

}
