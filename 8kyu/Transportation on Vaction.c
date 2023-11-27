/* d - the days to rent */
unsigned rental_car_cost(unsigned d)
{

 unsigned cost = d * 40;
 
 if(d<3)
   return cost;
   
 if(d<7)
   return cost - 20;
 
 return cost - 50; 
    
    
}

//mine
/* d - the days to rent */
unsigned rental_car_cost(unsigned d)
{ 
    unsigned cost = 0u;
    if(d >= 7u)
    {
      cost = d * 40u - 50u;
    }
    else if( d>= 3u)
    {
      cost = d * 40u - 20u;
    }
    else
    {
      cost = d * 40u;
    }
    return cost;
}