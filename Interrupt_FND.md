1. Interrupt

1) 인터럽트란?

- 어떤 사건이 발생하면 미리 지정된 위치로 분기하여 인터럽트를 처리하고, 처리가 끝나면 인터럽트 코드로 분기하기 전의 위치로 복귀하여 작업을 계속 수행함

- 하드웨어가 CPU에게 일을 처리해 달라고 요청하는 수단

- 인터럽트 서비스 루틴 (ISR) : 인터럽트를 처리하는 프로그램

![image](https://user-images.githubusercontent.com/87634136/173245574-b48826b3-3626-44b4-bb01-3d5550413f2d.png)


2) 인터럽트의 종류

![image](https://user-images.githubusercontent.com/87634136/173245589-6c7e0cdf-77bb-4ef5-8de9-d067656d3d8e.png)

- 마이크로 컨트롤러의 외부 입출력 방법

   -> 마이크로 컨트롤러에서 입력을 받아들이는 방법
   
      ![image](https://user-images.githubusercontent.com/87634136/173245601-84ab1df1-496a-4be5-aca1-2f37f540326c.png)

   ; 인터럽트는 방생 시기를 예측하기 힘든 경우에 마이크로 컨트롤러가 가장 빠르게 대응할 수 있는 방법


3) 인터럽트 처리 과정 

![image](https://user-images.githubusercontent.com/87634136/173245622-972994e1-76c2-43fe-96e1-79a7800e4c01.png)

예시)

1. 독서를 하다가 초인종이 울리면

2. 현재 독서하고 있는 페이지를 저장하고

3. 초인종에 대한 처리를 한 후

4. 다시 책의 읽던 부분으로 돌아와 읽음

![image](https://user-images.githubusercontent.com/87634136/173245639-6a5837d6-cb32-4a65-94fb-fe298db772df.png)


4) 인터럽트 구성요소

![image](https://user-images.githubusercontent.com/87634136/173245658-1735dd29-2193-4fcc-b2be-af19e3a7246b.png)

; 인터럽트 벡터는 인터럽트가 발생하였을 때 해야 할 일이 무엇인가를 정해 놓은 것으로, 인터럽트 서비스 루틴 (ISR)의 시작 주소임

- ATmega128의 인터럽트 

![image](https://user-images.githubusercontent.com/87634136/173245680-d3965a3f-0232-4a5e-bbad-dcfcbf7aedee.png)


5) 인터럽트 허용/금지

![image](https://user-images.githubusercontent.com/87634136/173245699-610404b4-1022-4313-8f16-98689d34117e.png)


6) 인터럽트 관련 레지스터

< 전체 >

![image](https://user-images.githubusercontent.com/87634136/173245708-c597a6c8-5c12-49d2-bcd7-ffe1345f30b5.png)

![image](https://user-images.githubusercontent.com/87634136/173245720-527ab5a0-7bce-4145-bb2c-86d5fe7cf48a.png)

![image](https://user-images.githubusercontent.com/87634136/173245729-aaba1ad6-6729-4860-9125-1aaa0cbf98a9.png)

![image](https://user-images.githubusercontent.com/87634136/173245736-b0de157b-6b28-4c84-8e4a-6267f11adb6a.png)


7) 변수의 범위, 수명, volatile

- 변수의 범위

![image](https://user-images.githubusercontent.com/87634136/173245748-b8a7e794-615a-4b3b-aed2-a1694e342d51.png)

- 변수의 수명

![image](https://user-images.githubusercontent.com/87634136/173245758-faaf772e-0735-4ae3-9a68-f4a643c9b819.png)

- Volatile 키워드

![image](https://user-images.githubusercontent.com/87634136/173245763-e6dacec8-a86b-4b4e-bf02-c8b7af037d98.png)



2. FND

1) FND란?

![image](https://user-images.githubusercontent.com/87634136/173245769-dcf7244a-3868-4774-80d1-bedb6ce81df6.png)

- LED (발광 다이오드)를 사용하여 숫자 모양을 하나로 만들어 놓은 것

- 7개의 조명편을 배치

- 그 몇 개를 선택하여 조명을 켜면서 0에서 9까지의 10진 디지트를 표시할 수 있도록 한 표시장치로 7세그먼트라고도 불림

- 주로 숫자를 표시하기 위해서 만들어진 LED의 조합


* FND 사용 방식 (FND 2개 기준)

1. 정적 : FND 포트 16개 사용, 트랜지스터 사용 X

2. 동적 : FND 포트 8개 사용, 트랜지스터 사용 O


2) FND 종류

![image](https://user-images.githubusercontent.com/87634136/173245780-b483fa17-365a-4b2f-86d0-6ecf46f644e4.png)

- FND 2개 기준

; 각 세그먼트의 LED 핀을 모두 뽑아 놓게 되면, 핀의 개수가 16개를 필요로 함 -> 이를 ANODE(애노드)나 CATHODE(캐소드)를 공통으로 묶은 후 핀을 내놓음

; FND는 COMMOM이 어떤 형태로 잡혀 있느냐에 따라 A, C COMMOM 타입으로 구분


* Common-anode type : 풀업 방식으로 연결함

* Common-cathode type : 풀다운 방식으로 연결함

![image](https://user-images.githubusercontent.com/87634136/173245788-2e1c013b-d2ed-45c0-ae07-7c12a2796619.png)


3) FND 간단한 동작 원리

![image](https://user-images.githubusercontent.com/87634136/173245794-1d0a2458-38ba-4107-a101-729abd4fb214.png)

- 전기적 신호를 공급하여 LED를 ON/OFF 시킴으로써 숫자를 표시함

- 필요한 숫자에 따라서 ON 시켜야 할 LED와 OFF 시켜야 할 LED에 맞추어 신호를 입력하여 숫자를 표시하게 됨

Ex1) 숫자 ‘1’을 표시하고자 한다면 ==> LED b와 c를 ON, 나머지는 모두 OFF

EX2) 숫자 ‘8’을 표시하고자 한다면 ==> a ,b, c, d, e, f, g를 모두 ON 


4) 다이나믹 구동

- 다이나믹 구동은 구동 회로를 단순하도록 만들기 위해 사용하는 방식

- 각각을 독립적으로 동작시킨 후 그 동작을 빠르게 회전시켜 잔상(POV)을 이용한 디스플레이 방식 

![image](https://user-images.githubusercontent.com/87634136/173245806-d55ba7be-0be0-4a11-af19-3cf1ad970e9d.png)


5) NPN, PNP 트랜지스터

![image](https://user-images.githubusercontent.com/87634136/173245822-3b157a46-26d4-4874-8889-a7f1fba1cb31.png)
