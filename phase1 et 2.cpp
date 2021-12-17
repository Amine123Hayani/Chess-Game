// NOM : M'Hammed EL MRABET           Group : B        
//rq: j'ai travailler seul

// phase de projet jeux d'echec


#include <iostream>
#include<string>
#include<stdlib.h> 
#include<vector>

using namespace std;

void initPlateau(int p[8][8], int &tj)
{
	int i,j;
	for(j=0 ; j<8 ; j++)
	{
		p[1][j]=1; 	//=> Pion
		p[6][j]=-1; //=> Pion
	}
	
	p[0][0]=3; // =>tour
	p[0][1]=2; // =>cheval
	p[0][2]=4; // =>Fou
	p[0][3]=5; // =>dame
	p[0][4]=6; // =>Roi
	p[0][5]=4; // =>Fou
	p[0][6]=2; // =>cheval
	p[0][7]=3; // =>tour
	p[7][0]=-3;// =>tour
	p[7][1]=-2; // =>cheval
	p[7][2]=-4;// =>Fou
	p[7][3]=-5; // =>dame
	p[7][4]=-6; // =>Roi
	p[7][5]=-4; // =>Fou
	p[7][6]=-2; // =>cheval
	p[7][7]=-3; // =>tour
	
	for(i=2;i<6;i++)
	{
		for(j=0;j<8;j++)
		{
			p[i][j]=0; // =>vide
		}
	}
	tj = 2;
}

void initJ(int j1,int j2,int &tj) // => choisir le type de joueur
{
	int choix;
	j1=1; j2=2;
	cout<<"Machine(2) VS Humain(1)"<<endl;
	cin>>choix;
	if(choix==1)
	{
		j2=2;
	}
	else
	{
		j2=3;
	}
	tj=1;
}

void print_Plat(int p[8][8])
{
	cout<<" |   0  |   1  |   2  |   3  |   4  |   5  |   6  |   7  |"<<endl; // nombre des colonnes
	cout<<""<<endl;

	for(int i=0;i<8;i++)
	{
		for(int j=0;j<8;j++)
		{
		 if(p[i][j]==1)
		 	{
			 cout<<" |  PB "; //=> pion blanche
			}
		 else if(p[i][j]==-1)
		 	{
			 cout<<" |  PN "; //=> pion noir
			}	
		 else if(p[i][j]==3)
			{
			 cout<<" |  TB "; //=>tour blanche
			}	
		 else if(p[i][j]==-3)
			{
			 cout<<" |  TN "; //=>tour noir
			}
		 else if(p[i][j]==2)
			{
			 cout<<" |  CB "; //=>cheval blanche
			}
		 else if(p[i][j]==-2)
			{
			 cout<<" |  CN "; //=>cheval noir
			}
		 else if(p[i][j]==4)
			{
			 cout<<" |  FB "; //=>Fou blanche
			}
		 else if(p[i][j]==-4)
			{
			 cout<<" |  FN "; //=>Fou noir
			}
		 else if(p[i][j]==5)
			{
			 cout<<" |  DB "; //=>dame blanche
			}
		 else if(p[i][j]==-5)
			{
			 cout<<" |  DN "; //=>dame noir
			}
		 else if(p[i][j]==6)
			{
	 		 cout<<" |  RB "; //=>roi blanche
			}
		 else if(p[i][j]==-6)
			{
			 cout<<" |  RN "; //=>roi noir
			}
		 if(p[i][j]==0)
			{
			 cout<<" |     ";
			}
		}
	 cout<<" |"<<i<<endl; // => i represent nombre des ligne
 	}

}								
// fonction qui retourn true si le pion est a son position d origine																															  
bool First_MoveN(int p[8][8] , int xd , int yd, int xa ,int ya)
{
	if(p[6][yd]==-1)
	{
		return true;
	}
	else
	{
		return false;
	}
}
bool First_MoveB(int p[8][8] , int xd , int yd, int xa ,int ya)
{
    if(p[1][yd]==1)
	{
		return true;
	}
	else
	{
		return false;
	}
}

void check_Pion(int p[8][8] , int xd , int yd, int xa ,int ya)
{
	
	if(p[xd][yd]==-1)
	{
		if(First_MoveN(p,xd,yd,xa,ya)==true)
		{
			if(xa==xd-2 && ya==yd)												
			{																					              
				p[xd][yd]=0;																	
				p[xd-2][yd]=-1;																
			}
			if(xa==xd-1 && ya==yd)												
			{																					              
				p[xd][yd]=0;																	
				p[xd-1][yd]=-1;	
			}
		}																						    
		else if(First_MoveN(p,xd,yd,xa,ya)==false)
		{				
			if(xa==xd-1 && ya==yd)												
			{																					              
				p[xd][yd]=0;																	
				p[xd-1][yd]=-1;																
			}
		}
	}
	if(p[xd][yd]==1)
	{
		if(First_MoveB(p,xd,yd,xa,ya)==true)
		{
			if(xa==xd+2 && ya==yd)												
			{																					              
				p[xd][yd]=0;																	
				p[xd+2][yd]=1;																
			}																			    
			if(xa==xd+1 && ya==yd)
			{	
				p[xd][yd]=0;
				p[xd+1][yd]=1;
			}
		}
		else if(First_MoveB(p,xd,yd,xa,ya)==false)
		{
			
			if(xa==xd+1 && ya==yd)
			{	
				p[xd][yd]=0;
				p[xd+1][yd]=1;
			}
		}
	}
}

// => les mouvement de cheval utilise dans la procedur check_cheval(p,xd,yd,xa,ya)

						//     0   1   2   3   4   5   6   7
						//   *********************************
			     		//   *   *   *   *    *   *   *   *   *  0              
						//   *********************************
						//   *   *   *&&&*    *&&&*   *   *   *  1														
					    //   *********************************
					    //   *   *&&&*   *    *   *&&&*   *   *  2
						//   *********************************
						//   *   *   *   * CN *   *   *   *   *  3             
						//   *********************************
						//   *   *&&&*   *    *   *&&&*   *   *  4															
					    //   *********************************
						//   *   *   *&&&*    *&&&*   *   *   *  5
						//   *********************************
						//   *   *   *   *    *   *   *   *   *  6             
						//   *********************************
						//   *   *   *   *    *   *   *   *   *  7								
					    //   *********************************

//  &&&: est les mouvement possible 

void check_cheval(int p[8][8] , int xd , int yd , int xa ,int ya)
{
	if(p[xd][yd]==2)
	{
		if(xa==xd+1 && ya==yd+2)											
		{
			p[xd+1][yd+2]=2;
			p[xd][yd]=0;			
		}
		if(xa==xd-1 && ya==yd+2)								
		{
			p[xd-1][yd+2]=2;
			p[xd][yd]=0;			
		}
		if(xa==xd+1 && ya==yd-2)										
		{
			p[xd+1][yd-2]=2;
			p[xd][yd]=0;			
		}
		if(xa==xd-1 && ya==yd-2)																
		{			
			p[xd-1][yd-2]=2;
			p[xd][yd]=0;			
		}
		if(xa==xd+2 && ya==yd+1)																
		{		
			p[xd+2][yd+1]=2;	
			p[xd][yd]=0;		
		}
		if(xa==xd-2 && ya==yd+1)																	
		{			
			p[xd-2][yd+1]=2;
			p[xd][yd]=0;			
		}
		if(xa==xd+2 && ya==yd-1)														 
		{
			p[xd+2][yd-1]=2;
			p[xd][yd]=0;			
		}
		if(xa==xd-2 && ya==yd-1)																			 
		{
			p[xd-2][yd-1]=2;
			p[xd][yd]=0;			
		}		
	}
	if(p[xd][yd]==-2)
	{
		if(xa==xd+1 && ya==yd+2)											
		{
			p[xd+1][yd+2]=-2;
			p[xd][yd]=0;			
		}
		if(xa==xd-1 && ya==yd+2)											
		{
			p[xd-1][yd+2]=-2;
			p[xd][yd]=0;			
		}
		if(xa==xd+1 && ya==yd-2)										 
		{
			p[xd+1][yd-2]=-2;
			p[xd][yd]=0;			
		}
		if(xa==xd-1 && ya==yd-2)											
		{			
			p[xd-1][yd-2]=-2;
			p[xd][yd]=0;			
		}
		if(xa==xd+2 && ya==yd+1)																
		{
			p[xd+2][yd+1]=-2;	
			p[xd][yd]=0;		
		}
		if(xa==xd-2 && ya==yd+1)																		
		{
			p[xd-2][yd+1]=-2;
			p[xd][yd]=0;			
		}
		if(xa==xd+2 && ya==yd-1)														 
		{
			p[xd+2][yd-1]=-2;
			p[xd][yd]=0;			
		}
		if(xa==xd-2 && ya==yd-1)																			
		{
			p[xd-2][yd-1]=-2;
			p[xd][yd]=0;			
		}
	}		
}

// => les mouvement de tour utilise dans la procedur check_tour(p,xd,yd,xa,ya)

						//     0   1   2   3   4   5   6   7
						//   *********************************
			     		//   *   *   *   *&&&&*   *   *   *   *  0              
						//   *********************************
						//   *   *   *   *&&&&*   *   *   *   *  1														
					    //   *********************************
					    //   *   *   *   *&&&&*   *   *   *   *  2
						//   *********************************
						//   *&&&*&&&*&&&* TN *&&&*&&&*&&&*&&&*  3             
						//   *********************************
						//   *   *   *   *&&&&*   *   *   *   *  4															
					    //   *********************************
						//   *   *   *   *&&&&*   *   *   *   *  5
						//   *********************************
						//   *   *   *   *&&&&*   *   *   *   *  6             
						//   *********************************
						//   *   *   *   *&&&&*   *   *   *   *  7								
					    //   *********************************

//  &&&: est les mouvement possible 

void check_tour(int p[8][8] , int xd , int yd , int xa, int ya)
{
	int i,j,r,k,cp;
	
	if(p[xd][yd]==3)
	{		
	
		for(i=0;i<=7;i++)
		{	
			if(xa==xd+i && ya==yd)                      //deplacement en bas en meme colonne et different ligne
			{	
				p[xd+i][yd]=3;
				p[xd][yd]=0;
				cp=xd+i;
			}	
			if(cp==xa)
			{
				i=8;
			}
		}	
		
		for(k=0;k<=7;k++)
		{
			if(xa==xd && ya==yd+k)						//deplacement a droit en meme ligne et different colonne
			{										
						p[xd][yd+k]=3;	
						p[xd][yd]=0;
						cp=yd+k;			
			}
			if(cp==ya)
			{
				k=8;
			}
		}
		for(j=7;j>=0;j--)						   	
		{				
			if(xa==xd-j && ya==yd)						//deplacement en haut en meme colonne et differnet ligne
			{
				p[xd-j][yd]=3;
				p[xd][yd]=0;
				cp=xd-j;		
			}
			if(cp == xa)
			{
				i=8;
			}
		}
		for(r=7;r>=0;r--)
		{
			if(xa==xd && ya==yd-r)						//deplacement a gauche en meme ligne et different colonnne
			{
				p[xd][yd-r]=3;
				p[xd][yd]=0;
				cp=yd-r;
			}
			if(cp==ya)
			{
				j=8;
			}
		}
	}
	if(p[xd][yd]==-3)
	{
		for(i=0;i<=7;i++)
		{
			if(xa==xd+i && ya==yd)                      //deplacement en bas en meme colonne et different ligne
				{	
					p[xd+i][yd]=-3;
					p[xd][yd]=0;
					cp=xd+i;
				}	
				if(cp==xa)
				{
					i=8;
				}
		}	
				
		for(k=0;k<=7;k++)
		{
			if(xa==xd && ya==yd+k)						//deplacement a droit en meme ligne et different colonne
			{										
						p[xd][yd+k]=-3;	
						p[xd][yd]=0;
						cp=yd+k;			
			}
			if(cp==ya)
			{
				k=8;
			}
		}
		for(j=7;j>=0;j--)						   	
		{				
			if(xa==xd-j && ya==yd)						//deplacement en haut en meme colonne et differnet ligne
			{
				p[xd-j][yd]=-3;
				p[xd][yd]=0;
				cp=xd-j;		
			}
			if(cp == xa)
			{
				i=8;
			}
		}
		for(r=7;r>=0;r--)
		{
			if(xa==xd && ya==yd-r)						//deplacement a gauche en meme ligne et different colonnne
			{
				p[xd][yd-r]=-3;
				p[xd][yd]=0;
				cp=yd-r;
			}
			if(cp==ya)
			{
				j=8;
			}
		}
	}
}		
// => les mouvement de fou utilise dans la procedur check_Fou(p,xd,yd,xa,ya)

						//     0   1   2   3   4   5   6   7
						//   *********************************
			     		//   *&&&*   *   *    *   *   *&&&*   *  0              
						//   *********************************
						//   *   *&&&*   *    *   *&&&*   *   *  1														
					    //   *********************************
					    //   *   *   *&&&*    *&&&*   *   *   *  2
						//   *********************************
						//   *   *   *   * FN *   *   *   *   *  3             
						//   *********************************
						//   *   *   *&&&*    *&&&*   *   *   *  4															
					    //   *********************************
						//   *   *&&&*   *    *   *&&&*   *   *  5
						//   *********************************
						//   *&&&*   *   *    *   *   *&&&*   *  6             
						//   *********************************
						//   *   *   *   *    *   *   *   *&&&*  7								
					    //   *********************************

//  &&&: est les mouvement possible 
void check_Fou(int p[8][8],int &xd,int &yd,int &xa,int &ya)
{
	int i,j,k,r,cp,tot;
	if(p[xd][yd]==4)
	{
		for(i=0;i<=7;i++)
		{
			if(xa==xd+i && ya==yd+i)			 //deplacement en bas a droit a travers une diagonal
			{
				p[xd+i][yd+i]=4;
				p[xd][yd]=0;
				cp=xd+i; tot=yd+i;
			}
			if(cp==xa && yd==ya)
			{
				i=8;
			}
		}
		for(j=1;j<=7;j++)
		{
			if(xa==xd+j && ya==yd-j)			//deplacement en bas a gauche a travers une diagonal
			{
				p[xd+j][yd-j]=4;	
				p[xd][yd]=0;
				cp=xd+j; tot=yd-j;
			}
			if(cp==xa && tot==ya)
			{
				j=8;
			}		
		}
		for(k=0;k<=7;k++)
		{
			if(xa==xd-k && ya==yd-k)			//deplacement en haut a gauche a travers une diagonal
			{
				p[xd-k][yd-k]=4;
				p[xd][yd]=0;
				cp=xd=k; tot=yd-k;
			}
			if(cp==xa && tot==ya)
			{
				k=8;
			}
		}		
		for(r=0;r<=7;r++)						//deplacement en haut a droite a travers une diagonal
		{
			if(xa==xd-r && ya==yd+r)
			{
				p[xd-r][yd+r]=4;
				p[xd][yd]=0;
				cp=xd-r; tot=yd+r;
			}
			if(cp==xa && tot==ya)
			{
				r=8;
			}
		}			
	}
	if(p[xd][yd]==-4)
	{
		for(i=0;i<=7;i++)
		{
			if(xa==xd+i && ya==yd+i)			 //deplacement en bas a droit a travers une diagonal
			{
				p[xd+i][yd+i]=-4;
				p[xd][yd]=0;
				cp=xd+i; tot=yd+i;
			}
			if(cp==xa && yd==ya)
			{
				i=8;
			}
		}
		for(j=1;j<=7;j++)
		{
			if(xa==xd+j && ya==yd-j)			//deplacement en bas a gauche a travers une diagonal
			{
				p[xd+j][yd-j]=-4;	
				p[xd][yd]=0;
				cp=xd+j; tot=yd-j;
			}
			if(cp==xa && tot==ya)
			{
				j=8;
			}		
		}
		for(k=0;k<=7;k++)
		{
			if(xa==xd-k && ya==yd-k)			//deplacement en haut a gauche a travers une diagonal
			{
				p[xd-k][yd-k]=-4;
				p[xd][yd]=0;
				cp=xd=k; tot=yd-k;
			}
			if(cp==xa && tot==ya)
			{
				k=8;
			}
		}		
		for(r=0;r<=7;r++)						//deplacement en haut a droite a travers une diagonal
		{
			if(xa==xd-r && ya==yd+r)
			{
				p[xd-r][yd+r]=-4;
				p[xd][yd]=0;
				cp=xd-r; tot=yd+r;
			}
			if(cp==xa && tot==ya)
			{
				r=8;
			}
		}		
	}
		
}
// => les mouvement de roi utilise dans la procedur check_roi(p,xd,yd,xa,ya)

						//     0   1   2   3   4   5   6   7
						//   *********************************
						//   *   *   *   *    *   *   *   *   *  0              
						//   *********************************
						//   *   *   *   *    *   *   *   *   *  1														
						//   *********************************
						//   *   *   *&&&*&&&&*&&&*   *   *   *  2
						//   *********************************
						//   *   *   *&&&* RN *&&&*   *   *   *  3             
						//   *********************************
						//   *   *   *&&&*&&&&*&&&*   *   *   *  4															
						//   *********************************
						//   *   *   *   *    *   *   *   *   *  5
						//   *********************************
						//   *   *   *   *    *   *   *   *   *  6             
						//   *********************************
						//   *   *   *   *    *   *   *   *   *  7								
						//   *********************************

//  &&&: est les mouvement possible 	

void check_Roi(int p[8][8],int xd,int yd,int xa,int ya)
{
	if(p[xd][yd]==6)
	{
		if(xa==xd+1 && ya==yd+1)  //deplacement en bas a droit par une case d'une maniere diagonal
		{
			p[xd+1][yd+1]=6;
			p[xd][yd]=0;
		}
		
		if(xa==xd+1 && ya==yd-1)  //deplacement en bas a gauche par une case d'une maniere diagonal
		{
			p[xd+1][yd-1]=6;
			p[xd][yd]=0;
		}	
		if(xa==xd-1 && ya==yd-1)  //deplacement en haut a gauche par une case d'une maniere diagonal
		{
			p[xd-1][yd-1]=6;
			p[xd][yd]=0;
		}
		
		if(xa==xd-1 && ya==yd+1)	//deplacement en haut a droit par une case d'une maniere diagonal
		{
			p[xd-1][yd+1]=6;
			p[xd][yd]=0;
		}
			
		if(xa==xd+1 && ya==yd)	 	//deplacement en bas par une case en meme colonne 
		{		
			p[xd+1][yd]=6;
			p[xd][yd]=0;			
		}
						
		if(xa==xd && ya==yd+1)		//deplacement a droit en meme ligne par une case
	    {									
			p[xd][yd+1]=6;
			p[xd][yd]=0;			
		}
		if(xa==xd-1 && ya==yd)     //deplacement en haut par une case en meme colonne 
		{				
			p[xd-1][yd]=6;
			p[xd][yd]=0;
		}
		if(xa==xd && ya==yd-1)	   ////deplacement a gauche en meme ligne par une case
		{
			p[xd][yd-1]=6;
			p[xd][yd]=0;
		}
	}
	
	if(p[xd][yd]==-6)
	{
		if(xa==xd+1 && ya==yd+1)  //deplacement en bas a droit par une case d'une maniere diagonal
		{
			p[xd+1][yd+1]=-6;
			p[xd][yd]=0;
		}
		if(xa==xd+1 && ya==yd-1)  //deplacement en bas a gauche par une case d'une maniere diagonal
		{
			p[xd+1][yd-1]=-6;
			p[xd][yd]=0;
		}	
		if(xa==xd-1 && ya==yd-1)  //deplacement en haut a gauche par une case d'une maniere diagonal
		{
			p[xd-1][yd-1]=-6;
			p[xd][yd]=0;
		}
		if(xa==xd-1 && ya==yd+1)		 //deplacement en haut a droit par une case d'une maniere diagonal
		{
			p[xd-1][yd+1]=-6;
			p[xd][yd]=0;
		}			
		if(xa==xd+1 && ya==yd)	 	//deplacement en bas par une case en meme colonne 
		{		
			p[xd+1][yd]=-6;
			p[xd][yd]=0;			
		}						
		if(xa==xd && ya==yd+1)		//deplacement a droit en meme ligne par une case
	    {									
			p[xd][yd+1]=-6;
			p[xd][yd]=0;			
		}
		if(xa==xd-1 && ya==yd)     //deplacement en haut par une case en meme colonne 
		{				
			p[xd-1][yd]=-6;
			p[xd][yd]=0;
		}
		if(xa==xd && ya==yd-1)	   ////deplacement a gauche en meme ligne par une case
		{
			p[xd][yd-1]=-6;
			p[xd][yd]=0;
		}
	}
}
// => les mouvement de dame utilise dans la procedur check_dame(p,xd,yd,xa,ya)

						//     0   1   2   3   4   5   6   7
						//   *********************************
						//   *&&&*   *   *&&&&*   *   *&&&*   *  0              
						//   *********************************
						//   *   *&&&*   *&&&&*   *&&&*   *   *  1														
						//   *********************************
						//   *   *   *&&&*&&&&*&&&*   *   *   *  2
						//   *********************************
						//   *&&&*&&&*&&&* DN *&&&*&&&*&&&*&&&*  3             
						//   *********************************
						//   *   *   *&&&*&&&&*&&&*   *   *   *  4															
						//   *********************************
						//   *   *&&&*   *&&&&*   *&&&*   *   *  5
						//   *********************************
						//   *&&&*   *   *&&&&*   *   *&&&*   *  6             
						//   *********************************
						//   *   *   *   *&&&&*   *   *   *&&&*  7								
						//   *********************************

//  &&&: est les mouvement possible 	
void check_Dame(int p[8][8] , int xd , int yd ,int xa,int ya)
{
	int i,j,k,r,tot,cp;
	if(p[xd][yd]==5)
	{
		for(i=0;i<=7;i++)
		{	
			if(xa==xd+i && ya==yd)                      //deplacement en bas en meme colonne et different ligne
			{	
				p[xd+i][yd]=5;
				p[xd][yd]=0;
				cp=xd+i;
			}	
			if(cp==xa)
			{
				i=8;
			}
		}	
		
		for(k=0;k<=7;k++)
		{
			if(xa==xd && ya==yd+k)						//deplacement a droit en meme ligne et different colonne
			{										
						p[xd][yd+k]=5;	
						p[xd][yd]=0;
						cp=yd+k;			
			}
			if(cp==ya)
			{
				k=8;
			}
		}
		for(j=7;j>=0;j--)						   	
		{				
			if(xa==xd-j && ya==yd)						//deplacement en haut en meme colonne et differnet ligne
			{
				p[xd-j][yd]=5;
				p[xd][yd]=0;
				cp=xd-j;		
			}
			if(cp == xa)
			{
				i=8;
			}
		}
		for(r=7;r>=0;r--)
		{
			if(xa==xd && ya==yd-r)						//deplacement a gauche en meme ligne et different colonnne
			{
				p[xd][yd-r]=5;
				p[xd][yd]=0;
				cp=yd-r;
			}
			if(cp==ya)
			{
				j=8;
			}
		}
		
		for(i=0;i<=7;i++)
		{
			if(xa==xd+i && ya==yd+i)			 //deplacement en bas a droit a travers une diagonal
			{
				p[xd+i][yd+i]=5;
				p[xd][yd]=0;
				cp=xd+i; tot=yd+i;
			}
			if(cp==xa && yd==ya)
			{
				i=8;
			}
		}
		for(j=1;j<=7;j++)
		{
			if(xa==xd+j && ya==yd-j)			//deplacement en bas a gauche a travers une diagonal
			{
				p[xd+j][yd-j]=5;	
				p[xd][yd]=0;
				cp=xd+j; tot=yd-j;
			}
			if(cp==xa && tot==ya)
			{
				j=8;
			}		
		}
		for(k=0;k<=7;k++)
		{
			if(xa==xd-k && ya==yd-k)			//deplacement en haut a gauche a travers une diagonal
			{
				p[xd-k][yd-k]=5;
				p[xd][yd]=0;
				cp=xd=k; tot=yd-k;
			}
			if(cp==xa && tot==ya)
			{
				k=8;
			}
		}		
		for(r=0;r<=7;r++)						//deplacement en haut a droite a travers une diagonal
		{
			if(xa==xd-r && ya==yd+r)
			{
				p[xd-r][yd+r]=5;
				p[xd][yd]=0;
				cp=xd-r; tot=yd+r;
			}
			if(cp==xa && tot==ya)
			{
				r=8;
			}
		}			
	}
	
	if(p[xd][yd]==-5)
	{
		 for(i=0;i<=7;i++)
		{	
			if(xa==xd+i && ya==yd)                      //deplacement en bas en meme colonne et different ligne
			{	
				p[xd+i][yd]=-5;
				p[xd][yd]=0;
				cp=xd+i;
			}	
			if(cp==xa)
			{
				i=8;
			}
		}	
		
		for(k=0;k<=7;k++)
		{
			if(xa==xd && ya==yd+k)						//deplacement a droit en meme ligne et different colonne
			{										
						p[xd][yd+k]=-5;	
						p[xd][yd]=0;
						cp=yd+k;			
			}
			if(cp==ya)
			{
				k=8;
			}
		}
		for(j=7;j>=0;j--)						   	
		{				
			if(xa==xd-j && ya==yd)						//deplacement en haut en meme colonne et differnet ligne
			{
				p[xd-j][yd]=-5;
				p[xd][yd]=0;
				cp=xd-j;		
			}
			if(cp == xa)
			{
				i=8;
			}
		}
		for(r=7;r>=0;r--)
		{
			if(xa==xd && ya==yd-r)						//deplacement a gauche en meme ligne et different colonnne
			{
				p[xd][yd-r]=-5;
				p[xd][yd]=0;
				cp=yd-r;
			}
			if(cp==ya)
			{
				j=8;
			}
		}
		for(i=0;i<=7;i++)
		{
			if(xa==xd+i && ya==yd+i)			 //deplacement en bas a droit a travers une diagonal
			{
				p[xd+i][yd+i]=-5;
				p[xd][yd]=0;
				cp=xd+i; tot=yd+i;
			}
			if(cp==xa && yd==ya)
			{
				i=8;
			}
		}
		for(j=1;j<=7;j++)
		{
			if(xa==xd+j && ya==yd-j)			//deplacement en bas a gauche a travers une diagonal
			{
				p[xd+j][yd-j]=-5;	
				p[xd][yd]=0;
				cp=xd+j; tot=yd-j;
			}
			if(cp==xa && tot==ya)
			{
				j=8;
			}		
		}
		for(k=0;k<=7;k++)
		{
			if(xa==xd-k && ya==yd-k)			//deplacement en haut a gauche a travers une diagonal
			{
				p[xd-k][yd-k]=-5;
				p[xd][yd]=0;
				cp=xd=k; tot=yd-k;
			}
			if(cp==xa && tot==ya)
			{
				k=8;
			}
		}		
		for(r=0;r<=7;r++)						//deplacement en haut a droite a travers une diagonal
		{
			if(xa==xd-r && ya==yd+r)
			{
				p[xd-r][yd+r]=-5;
				p[xd][yd]=0;
				cp=xd-r; tot=yd+r;
			}
			if(cp==xa && tot==ya)
			{
				r=8;
			}
		}			
	}		
}
//si les piece roi est tour est en position d origine et les case entre le oi et la tour vide tu peut fait un roque pour la protection
void Roque_blanche(int p[8][8],int xd , int yd ,int xa,int ya)
{
	int choix;
	if(p[0][4]==6 && p[0][7]==3 && p[0][6]==0 && p[0][5]==0)
	{			
		cout<<"si tu veux appliquer une roque entrer [1] sinon entrer [2]"<<endl;  
		cin>>choix;
		switch(choix)
		{
			case 1 :p[0][5]=3;
					p[0][6]=6;
					p[0][4]=0;
					p[0][7]=0; break;
					default : break;
		}		
	}
	if(p[0][4]==6 && p[0][0]==3 && p[0][1]==0 && p[0][2]==0 && p[0][3]==0)
	{	
		cout<<"si tu veux appliquer une roque entrer [1] sinon entrer [2]"<<endl;  
		cin>>choix;
		switch(choix)
		{
			case 1: p[0][2]=6;
					p[0][3]=3;
					p[0][4]=0;
					p[0][0]=0;
					p[0][1]=0; break;
					default : break;
		}
	}
}
void Roque_Noir(int p[8][8],int xd , int yd ,int xa,int ya)
{
	int choix;
	
	if(p[7][4]==-6 && p[7][7]==-3 && p[7][6]==0 && p[7][5]==0)
	{
		cout<<"si tu veux appliquer une roque entrer [1] sinon entrer [2]"<<endl;  
		cin>>choix;
		switch(choix)
		{
			case 1:	p[7][5]=-3;
					p[7][6]=-6;
					p[7][4]=-0;
					p[7][7]=-0; break;
					default : break;
		}
	}
	if(p[7][4]==-6 && p[7][0]==-3 && p[7][1]==0 && p[7][2]==0 && p[7][3]==0)
	{
		cout<<"si tu veux appliquer une roque entrer [1] sinon entrer [2]"<<endl;  
		cin>>choix;
		switch(choix)
		{
			case 1 : p[7][2]=-6;
					 p[7][3]=-3;
				   	 p[7][4]=0;
					 p[7][0]=0;
					 p[7][1]=0; break;
					 default : break;
		}
	}
}
//la promotion d'un pion consiste à le remplacer immédiatement par une autre pièce lorsqu'il arrive sur la dernière rangée.
void promotion(int p[8][8] , int xd , int yd ,int xa,int ya)
{
	int choix;
	if(p[0][yd]==-1)
	{
		cout<<"si tu veux changer au cavalier [1]"<<endl;
		cout<<"si tu veux chenger au fou      [2]"<<endl;
		cout<<"si tu veux changer au tour     [3]"<<endl;
		cout<<"si tu veux changer au dame     [4]"<<endl;
		cin>>choix;
		switch(choix)
		{
			case 1: p[0][yd]=-2; break;
			
			case 2: p[0][yd]=-4; break;
			
			case 3: p[0][yd]=-3; break;
			
			case 4: p[0][yd]=-5; break;
			
					default : break;		
		}
	}
	if(p[7][yd]==1)
	{
		cout<<"si tu veux changer au cavalier [1]"<<endl;
		cout<<"si tu veux chenger au fou      [2]"<<endl;
		cout<<"si tu veux changer au tour     [3]"<<endl;
		cout<<"si tu veux changer au dame     [4]"<<endl;
		cin>>choix;
		switch(choix)
		{
			case 1: p[7][yd]=2; break;
					
			case 2: p[7][yd]=4; break;
			
			case 3: p[7][yd]=3; break;
			
			case 4: p[7][yd]=5; break;
			
					default : break;		
		}
	}
}
//la prise en passant est une possibilité particulière de capturer un pion. Lorsqu’un pion se trouve sur la cinquième rangée 
//et que l’adversaire avance de deux cases un pion d’une colonne voisine, le premier pion peut prendre le second.
void prise_en_passant(int p[8][8] , int xd , int yd ,int xa,int ya)
{
	bool first_move1,first_move2;
	first_move1=First_MoveB(p,xd,yd,xa,ya);
	first_move2=First_MoveN(p,xd,yd,xa,ya);
	if(p[3][yd]==-1 && p[3][yd+1]==1 || p[3][yd-1]==1 && first_move1==true )
	{
		if(xa==xd-1 && ya==yd-1)
		{
			p[xd-1][yd-1]=-1;
			p[xd][yd]=0;
			p[xd][yd-1]=0;
		}
		if(xa==xd-1 && ya==yd+1)
		{
			p[xd-1][yd+1]=-1;
			p[xd][yd]=0;
			p[xd][yd+1]=0;
		}
	}
	if(p[4][yd]==1 && p[4][yd+1]==-1 || p[4][yd-1]==-1 && first_move2==true)
	{
		if(xa==xd+1 && ya==yd+1)
		{
			p[xd+1][yd+1]=1;
			p[xd][yd]=0;
			p[xd][yd+1]=0;
		}
		if(xa==xd+1 && ya==yd-1)
		{
			p[xd+1][yd-1]=1;
			p[xd][yd]=0;
			p[xd][yd-1]=0;
		}
	}
}


int Mouvement(int p[8][8] , int xd , int yd ,int xa,int ya)
{
	//pour les mouvements de pion
	if(p[xd][yd]==-1 || p[xd][yd]==1)
	{
		check_Pion(p,xd,yd,xa,ya);
	}

	// pour les mouvements de cheval
	if(p[xd][yd]==2 || p[xd][yd]==-2)
	{
		check_cheval(p,xd,yd,xa,ya);
	}

	// pour les mouvements de tour
	if(p[xd][yd]==3 || p[xd][yd]==-3)
	{
		check_tour(p,xd,yd,xa,ya);
	}

	// pour les mouvement de la fou
	if(p[xd][yd]==4 || p[xd][yd]==-4)
	{
		check_Fou(p,xd,yd,xa,ya);
	}
	
	//pour les mouvement de roi
	if(p[xd][yd]==6 || p[xd][yd]==-6)
	{
		check_Roi(p,xd,yd,xa,ya);
	}
	
	//pour les mouvements de la dame
	if(p[xd][yd]==5 || p[xd][yd]==-5)
	{
		check_Dame(p,xd,yd,xa,ya);
	}
}

void pos_Depart(int p[8][8] , int &tj , int &xd , int &yd) // procedure qui demande la position de la ligne(xd) et de la colonne(yd) de la piece a deplace
{														
	
	do
	{
		
		cout<<"donner le ligne de la piece a deplacer : "; cin>>xd; 	
		cout<<"donner la colonne de la piece a deplacer : "; cin>>yd; 
		
	}while(xd<0 || xd>7 || yd<0 || yd>7 || p[xd][yd]==0 || (tj==2 &&p[xd][yd]==-1 && p[xd-1][yd]!=0) || (tj==1 &&p[xd][yd]==1 && p[xd+1][yd]!=0));
	//les tests dans la boucle do while est pour etre sure que tout les position est dans le plateau de jeux
	
	if(tj==1 && p[xd][yd]<1 || tj==2 && p[xd][yd]>0) 
	{
		cout<<"!!! ce sont pas tes piece !!!"<<endl; 
	}
}

void pos_Arrivee(int p[8][8], int &tj ,int &xa,int &ya) // procedure qui demande la position de la ligne(xa) et de la colonne(ya) de la place qu on souhait 
{														// de mettre la piece qu ona deja choisie
	do
	{
		cout<<"donner le ligne d'arriver : "; cin>>xa; 
		cout<<"donner la colonne d'arriver : "; cin>>ya; 
	}while(xa>7 || xa<0 || ya>7 || ya<0);
	
}
//la procedur jouer a permet d'organizer les tours de jeux des joueurs c'est pour cela on donne le joueur 1 (tj==1) et le joueur 2 (tj==2)
//puis il demande au joueur de donner la position de la piece a deplace et aussi la position qu'on souhait a mettre la piece choisie
//puis on fait l'appel de la  procedure mouvement qui deplace la piece choisie d'apres les regles de mouvement de chaque piece
void jouer(int p[8][8], int tj)
{
	int xa,xd,ya,yd,choix;	
	
	
	if(tj==1)
	{				
				cout<<"PLAYER 1"<<endl;
				pos_Depart(p,tj,xd,yd); 
				pos_Arrivee(p,tj,xa,ya);
				Mouvement(p,xd,yd,xa,ya);
				promotion(p,xd,yd,xa,ya);	
				prise_en_passant(p,xd,yd,xa,ya);
				Roque_Noir(p,xd,yd,xa,ya);	
	}
	if(tj==2)
	{						
				cout<<"PLAYER 2"<<endl;
				pos_Depart(p,tj,xd,yd);
				pos_Arrivee(p,tj,xa,ya);  
				Mouvement(p,xd,yd,xa,ya);	
				promotion(p,xd,yd,xa,ya);
				prise_en_passant(p,xd,yd,xa,ya);
				Roque_blanche(p,xd,yd,xa,ya);
	}
}
int main()
{
	int check=1;
	int tj=0;
	int p[8][8];

//	initJ(j1,j2,tj);
	initPlateau(p,tj);
	
	do
	{
		print_Plat(p);
		jouer(p,tj);
		if (tj==1)
		{
			tj=2;
		}
		else
		{
			tj=1;
		}
	}while(check>0);
	return 0;
}

