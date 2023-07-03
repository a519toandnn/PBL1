//Đề 604
#include <bits/stdc++.h>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include<graphics.h>
#include<conio.h>
#include<dos.h>
#include <MMsystem.h>

using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef string str;
typedef pair <ll , ll> pll;

const ll MOD = 1e9 + 7;
const ll limit = 1e5 + 5;

char c[1000], p[3];
int cnt = 0, pos1, cR = 0, cW = 0, cY = 0, a[100];
bool check = true;

void stop()
{
	settextstyle( BOLD_FONT, HORIZ_DIR, 2);
    if (kbhit()) {
        char ch = getch();
			setcolor(WHITE);
			outtextxy(100,1000,"CHUONG TRINH DANG DUNG");
            while (1) 
			{
                if (kbhit()) 
				{
                    char ch2 = getch();
					setcolor(CYAN);
					outtextxy(100,1000,"CHUONG TRINH DANG DUNG");
                    break; 
            	}
            }
    }  
}

int main () {
    int i = 0;
    cout << "Nhap vao day bi, nhan E de thoat: ";
    double x, y;
	while (c[i] != 'E') {
        i ++;
        cnt ++;
        cin >> c[i];
        if (c[i] != 'R' && c[i] != 'Y' && c[i] != 'W' && c[i] != 'E') {
			cout << "Error!!!";
			return 0;
		}
		if (c[i] == 'E' && cnt == 1) {
			cout << "Empty!!!";
			return 0;
		}
        a[c[i]] ++;
    }
    
    
    cout << "Nhap vao thu tu sap xep: ";
    for (int i = 1; i <= 3; i ++) cin >> p[i];
    
	initwindow(2000, 2000);
	HWND hWnd, hWndChild;
  	hWnd = FindWindow(NULL, "Windows BGI");
  	hWndChild = GetWindow(hWnd, GW_CHILD);
  	char title[50];
  	sprintf(title, "BAI TOAN XEP SOI");
  	SendMessage((HWND) hWnd, WM_SETTEXT,0, (LPARAM)title);
	
	cleardevice();
	setbkcolor(CYAN);
	cleardevice();
	setbkcolor(CYAN);
	
    cnt --;
    
    int startX = 0, startY = 600;
    int endX = 1500, endY = 800;

	settextstyle (BOLD_FONT, HORIZ_DIR, 5);
   	outtextxy (700, 100, "BAI TOAN XEP SOI");
   	
   	int circleDistance = 1500 / (cnt);
   	int radius = circleDistance / 2;  
	
	if (cnt <= 6) {
		
		radius = 120;
		circleDistance = 260;
		
	}  	
	
	else if (cnt <= 12) {
		
		radius = 60;
		circleDistance = 150;
		
	}
   	for (int i = 1; i <= cnt; i++) {
   	
       int centerX = startX + (i * circleDistance);
       int centerY = startY;

       
       if (c[i] == 'R') {
    		setcolor(4);
    		circle(centerX, centerY, radius);
    		setfillstyle(1, RED);
            floodfill(centerX, centerY, RED);
        }
    		
       else if (c[i] == 'Y') {
	   		setcolor(14);
	   		circle(centerX, centerY, radius);
    		setfillstyle(1, YELLOW);
            floodfill(centerX, centerY, YELLOW);
        }
       else {
	   		setcolor(15);
	   		circle(centerX, centerY, radius);
    		setfillstyle(1, WHITE);
            floodfill(centerX, centerY, WHITE);
	   	}
       
   } 
   
    delay(1000);
   
    pos1 = a[p[1]] + a[p[2]];
    i = 1;
    int j = cnt, k = 1;
    
    while (k < 3) {

        if (a[p[k]] != 0) {

            if (c[i] != p[k]) {

                while (j >= 0) {

                    if (c[j] == p[k]) {

                        swap (c[i], c[j]);
                        
                        int i1 = i, j1 = j;
                        
                        int tmp = abs(i1 - j1);
                        
                        int centerX = startX + (i1 * circleDistance);
                        int centerY = startY;
                        setcolor(CYAN);
                        circle(centerX, centerY, radius);
                        setfillstyle(1, CYAN);
                        floodfill(centerX, centerY, CYAN);
                        
                        centerX = startX + (j1 * circleDistance);
                        centerY = startY;
                        setcolor(CYAN);
                        circle(centerX, centerY, radius);
                        setfillstyle(1, CYAN);
                        floodfill(centerX, centerY, CYAN);
                        
                        centerX = startX + (i1 * circleDistance);
                        centerY = startY + 300;
                        if (c[j] == 'R') {
    						setcolor(4);
    						circle(centerX, centerY, radius);
    						setfillstyle(1, RED);
            				floodfill(centerX, centerY, RED);
        				}
    		
       					else if (c[j] == 'Y') {
	   						setcolor(14);
	   						circle(centerX, centerY, radius);
    						setfillstyle(1, YELLOW);
            				floodfill(centerX, centerY, YELLOW);
        				}
       					else {
	   						setcolor(15);
	   						circle(centerX, centerY, radius);
    						setfillstyle(1, WHITE);
            				floodfill(centerX, centerY, WHITE);
	   					}
                        
                        centerX = startX + (j1 * circleDistance);
                        centerY = startY - 300;
                        if (c[i] == 'R') {
    						setcolor(4);
    						circle(centerX, centerY, radius);
    						setfillstyle(1, RED);
            				floodfill(centerX, centerY, RED);
        				}
    		
       					else if (c[i] == 'Y') {
	   						setcolor(14);
	   						circle(centerX, centerY, radius);
    						setfillstyle(1, YELLOW);
            				floodfill(centerX, centerY, YELLOW);
        				}
       					else {
	   						setcolor(15);
	   						circle(centerX, centerY, radius);
    						setfillstyle(1, WHITE);
            				floodfill(centerX, centerY, WHITE);
	   					}
                        
                        PlaySound(TEXT("D:\\tieng_ting.wav"), NULL, SND_SYNC);
                        
                       	stop();
                        
                        while (tmp != 0) {
                        		
                        	centerX = startX + (i1 * circleDistance);
                        	centerY = startY +300;
                        	setcolor(CYAN);
                        	circle(centerX, centerY, radius);
                        	setfillstyle(1, CYAN);
                        	floodfill(centerX, centerY, CYAN);
                        
                        	centerX = startX + (j1 * circleDistance);
                        	centerY = startY - 300;
                        	setcolor(CYAN);
                        	circle(centerX, centerY, radius);
                        	setfillstyle(1, CYAN);
                        	floodfill(centerX, centerY, CYAN);
                        	
                        	i1 ++;
                        	j1 --;
                        
                        	centerX = startX + (i1 * circleDistance);
                        	centerY = startY + 300;
                        	if (c[j] == 'R') {
    							setcolor(4);
    							circle(centerX, centerY, radius);
    							setfillstyle(1, RED);
            					floodfill(centerX, centerY, RED);
        					}
    		
       						else if (c[j] == 'Y') {
	   							setcolor(14);
	   							circle(centerX, centerY, radius);
    							setfillstyle(1, YELLOW);
            					floodfill(centerX, centerY, YELLOW);
        					}
       						else {
	   							setcolor(15);
	   							circle(centerX, centerY, radius);
    							setfillstyle(1, WHITE);
            					floodfill(centerX, centerY, WHITE);
	   						}
                        
                        	centerX = startX + (j1 * circleDistance);
                        	centerY = startY - 300;
                        	if (c[i] == 'R') {
    							setcolor(4);
    							circle(centerX, centerY, radius);
    							setfillstyle(1, RED);
            					floodfill(centerX, centerY, RED);
        					}
    		
       						else if (c[i] == 'Y') {
	   							setcolor(14);
	   							circle(centerX, centerY, radius);
    							setfillstyle(1, YELLOW);
            					floodfill(centerX, centerY, YELLOW);
        					}
       						else {
	   							setcolor(15);
	   							circle(centerX, centerY, radius);
    							setfillstyle(1, WHITE);
            					floodfill(centerX, centerY, WHITE);
	   						}
	   						
	   						PlaySound(TEXT("D:\\tieng_ting.wav"), NULL, SND_SYNC);
	   						
                        	stop();
                        	
                        	
                        	tmp --;
                        	//getch();
                        	
						}
						
						
						centerX = startX + (i1 * circleDistance);
                        centerY = startY + 300;
                        setcolor(CYAN);
                        circle(centerX, centerY, radius);
                        setfillstyle(1, CYAN);
                        floodfill(centerX, centerY, CYAN);
                        
                        centerX = startX + (j1 * circleDistance);
                        centerY = startY - 300;
                        setcolor(CYAN);
                        circle(centerX, centerY, radius);
                        setfillstyle(1, CYAN);
                        floodfill(centerX, centerY, CYAN);
                        
                        centerX = startX + (i1 * circleDistance);
                        centerY = startY;
                        if (c[j] == 'R') {
    						setcolor(4);
    						circle(centerX, centerY, radius);
    						setfillstyle(1, RED);
            				floodfill(centerX, centerY, RED);
        				}
    		
       					else if (c[j] == 'Y') {
	   						setcolor(14);
	   						circle(centerX, centerY, radius);
    						setfillstyle(1, YELLOW);
            				floodfill(centerX, centerY, YELLOW);
        				}
       					else {
	   						setcolor(15);
	   						circle(centerX, centerY, radius);
    						setfillstyle(1, WHITE);
            				floodfill(centerX, centerY, WHITE);
	   					}
                        
                        centerX = startX + (j1 * circleDistance);
                        centerY = startY;
                        if (c[i] == 'R') {
    						setcolor(4);
    						circle(centerX, centerY, radius);
    						setfillstyle(1, RED);
            				floodfill(centerX, centerY, RED);
        				}
    		
       					else if (c[i] == 'Y') {
	   						setcolor(14);
	   						circle(centerX, centerY, radius);
    						setfillstyle(1, YELLOW);
            				floodfill(centerX, centerY, YELLOW);
        				}
       					else {
	   						setcolor(15);
	   						circle(centerX, centerY, radius);
    						setfillstyle(1, WHITE);
            				floodfill(centerX, centerY, WHITE);
	   					}
	   					
	   					PlaySound(TEXT("D:\\tieng_ting.wav"), NULL, SND_SYNC);
	   					
                        stop();

                        j --;
                        i ++;
                        a[p[k]] --;
                        
                        break;

                    }

                    else {

                        j --;

                    }

                }

            }

            else {

                i ++;
                a[p[k]] --;

            }

        }

        else {

            j = cnt;
            k ++;

        }

    }
    for (int i = 1; i <= cnt; i ++) cout << c[i] << " ";
}