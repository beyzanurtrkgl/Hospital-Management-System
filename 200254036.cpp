
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Hastane{
	char firstLetter;
	struct kayit*next_hospital;
};


typedef Hastane hospital;

struct kayit{
	char name[50];
	char surname[50];
	int personld;
	char polyclinic[50];
	kayit* next;
	
};

typedef kayit record; 
hospital hospital_list[26];

int main()
{
	int total_record=0;
	char c;
	int i=0;
	
	for(c='a';c<='z';i++,c++)
	{
		
		hospital_list[i].firstLetter=c;
		hospital_list[i].next_hospital=NULL;
	}
	
	int secim;
	

	while(secim!=6)
	{	printf("1->Add New record\n2->Search Record \n3->Delete Record\n4->Sort Records By Name\n5->Sort Records By Surname\n");
		printf("6->Sort By Polyclinic Name\n7->Exit\n");
		printf("\n");
		printf("Enter choice=> ");
		scanf("%d",&secim);
		printf("\n");
			
	
		
		switch(secim)
		{
			case 1:
				
				{
					int index=0;
					char name[50];
					
					printf("Please Use Lowercase Letter \n");
					printf("Enter Name:");
					scanf("%s",&name);
					printf("\n");
					
				for(index=0; index<26; index++)	
					{	
						record *ilk_kayit = (record *) malloc(sizeof(record));
						hospital *hospital_list_item= &hospital_list[index];
						
						if(name[0]==hospital_list_item->firstLetter)
						
						{
								if(hospital_list_item->next_hospital==NULL)
								{
									ilk_kayit->next=NULL;
									printf("Please Enter Name Again:");
									scanf("%s",ilk_kayit->name);
									printf("Enter Surname:");
									scanf("%s",&ilk_kayit->surname);
									printf("Enter Person ID:");
									scanf("%d",&ilk_kayit->personld);
									printf("Enter Polyclinic Name (Orthodontics, Endoscopy, Implant and Cardiology):");
									scanf("%s",&ilk_kayit->polyclinic);
									hospital_list_item->next_hospital=ilk_kayit;
									printf("Recorded\n\n");
								}
								
								else
								{
									printf("Please Enter Name Again:");
									scanf("%s",ilk_kayit->name);
									printf("Enter Surname:");
									scanf("%s",&ilk_kayit->surname);
									printf("Enter Person ID:");
									scanf("%d",&ilk_kayit->personld);
									printf("Enter Polyclinic Name (Orthodontics, Endoscopy, Implant and Cardiology):");
									scanf("%s",&ilk_kayit->polyclinic);
									ilk_kayit->next = hospital_list_item->next_hospital;
                					hospital_list_item->next_hospital =ilk_kayit;
                					printf("Recorded\n\n");
							
								}	
							
					
						}
					}
					break;
				}
			
			case 2:
				{
					char search_name[50];
					char search_surname[50];
					int  search_personld;
					char  search_polyclinic[50];
					
					printf("Search Record\n");
					printf("Please Use Lowercase Letters\n");
					printf("Name:");
					scanf("%s",&search_name);
					
					printf("Surname:");
					scanf("%s",&search_surname);
					
					printf("Person ID:");
					scanf("%d",&search_personld);
					
					printf("Polyclinic:(Orthodontics, Endoscopy, Implant and Cardiology):");
					scanf("%s",&search_polyclinic);
					printf("\n");
						int i=0;
					for(char c='a'; c<='z'; c++, i++ )
					{	
						
						if(search_name[0]==c)
						{	
							record* recordd =hospital_list[i].next_hospital;
							int flag=0;
							while(flag!=1 && recordd!=NULL)
							{
							
								if((strcmp(search_name,recordd->name)==0)&&(strcmp(search_surname,recordd->surname)==0) && (strcmp(search_polyclinic,recordd->polyclinic)==0)&&(search_personld==recordd->personld)) 
								{
									printf("Searched Record Found: %s %s %d %s \n\n",search_name,search_surname,search_personld,search_polyclinic);
									flag=1;
								}
							recordd=recordd->next;
							}
							if(recordd==NULL && flag==0)
							{
								printf("Searched Record Not Found: %s %s %d %s \n\n",search_name,search_surname,search_personld,search_polyclinic);
							}
						}
						
						
					
					}
					break;
				}
			
			case 3:
				{
					char delete_name[50];
					char delete_surname[50];
					int delete_personld;
					char delete_polyclinic[50];
					
					printf("Delete search\n");
					printf("Please Use Lowercase Letters\n");
					printf("Name:");
					scanf("%s",&delete_name);
					
					printf("Surname:");
					scanf("%s",&delete_surname);
					
					printf("Person ID:");
					scanf("%d",&delete_personld);
					
					printf("Polyclinic:(Orthodontics, Endoscopy, Implant and Cardiology):");
					scanf("%s",&delete_polyclinic);
					printf("\n");
					
					for(int i=0; i<26; i++ )
					{	
						
						record* recordd =hospital_list[i].next_hospital;
						
						if(recordd==NULL)
						{
							continue;
						}
						int flag=0;
						while(recordd!=NULL && recordd->next!=NULL)
						{
							if((strcmp(delete_name,recordd->next->name)==0)&&(strcmp(delete_surname,recordd->next->surname)==0) && (strcmp(delete_polyclinic,recordd->next->polyclinic)==0)&&(delete_personld==recordd->next->personld)) 
							{
								record* temp= recordd->next;
								recordd->next=temp->next;
								free(temp);
								printf("Delete\n\n");
								flag=1;
								continue;
								
							}
							recordd=recordd->next;
						}
						
						if(strcmp(hospital_list[i].next_hospital->name,delete_name)==0 && strcmp(hospital_list[i].next_hospital->surname,delete_surname)==0 &&(hospital_list[i].next_hospital->personld==delete_personld) && strcmp(hospital_list[i].next_hospital->polyclinic,delete_polyclinic)==0 )
						{
							record*temp=hospital_list[i].next_hospital;
							hospital_list[i].next_hospital=temp->next;
							free(temp);
							flag=1;
							printf("Delete\n\n");
						}
						else if(flag!=0)
						{
							printf("There Is Not Such Record\n\n");
						}
						
						
					}
					
					
					break;
				}
				
			case 4:
				{
    				for (int i = 0; i < 26; i++) {
        			
					record *recordd = hospital_list[i].next_hospital;

      				if (recordd == NULL) continue;


       				while (recordd != NULL) {
            		printf("Record ID: %d, Record Name: %s, Record Surname: %s, Record Polyclinic: %s\n\n", recordd->personld, recordd->name, recordd->surname,
                   	recordd->polyclinic);
           			recordd = recordd->next;
        }}
					break;
				
				}
				
			case 5:
				{
					for (int i = 0; i < 26; i++) {
        			
					record *recordd = hospital_list[i].next_hospital;

      				if (recordd == NULL) continue;

       				while (recordd != NULL) {
            		printf("Record ID: %d, Record Name: %s, Record Surname: %s, Record Polyclinic: %s\n\n", recordd->personld, recordd->name, recordd->surname,
                   	recordd->polyclinic);
           			recordd = recordd->next;
        }}
					break;
					
				}
			
			
			case 6:
				{	
					printf("\n\n");
					printf("************************************Exit**********************************************************");
					break;
				}
			
			default:
				{
					printf("Entered Wrong Character\n");
					break;
				}
				
				
		}
	}
}
