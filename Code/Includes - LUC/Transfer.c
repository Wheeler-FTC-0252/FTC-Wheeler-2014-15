int transfer_J_To_M(int joy,float slope,int dead) // joy = joy input, dead = dead band, slope = max motor output/max joy input - in this case 100/128
{
	int y;
	if (abs(joy)<dead)
		y=0;
	else
		y=slope*((float)joy-(float)dead*sgn(joy));

	return y;
}
