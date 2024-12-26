# fractol
42서울의 2서클 과제입니다.

## 과제 소개
[소개 블로그](https://duckgi.tistory.com/13)

## 빌드 방법
- 빌드 명령어
```
make bonus
```

- 목적파일(.o)만 삭제
```
make clean
```

- 아카이브 파일(.a)까지 같이 삭제
```
make fclean
```

- fclean 후 다시 make
```
make re
```

## 실행 방법

1. Julia set
```
./fractol Julia num1 num2
```
ex) ./fractol Julia -0.4 0.6

2. Mandelbrot set
```
./fractol Mandelbort
```

3. Burning Ship set
```
./fractol Burning_ship
```


## 기능 설명
1. 색 변경  
	- 프로그램 실행 중 q, w, e, r 키를 눌러 색상을 변경할 수 있습니다.
  
2. 줌인, 줌아웃  
	- 마우스 커서를 중심으로 하여 휠을 이용해서 줌인, 줌아웃을 할 수 있습니다.
  
3. 화면 이동   
	- 키보드 방향키를 이용하여 원하는 화면으로 이동할 수 있습니다.
  
4. 종료  
	- 좌측 상단 모서리의 x 버튼이나 esc키를 이용하여 프로스램을 종료할 수 있습니다.
  
