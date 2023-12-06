# 기반 이미지 설정
FROM ubuntu:latest

# 필요한 패키지 설치
RUN apt-get update && \
    apt-get install -y make && \
    apt-get install -y g++ && \
    rm -rf /var/lib/apt/lists/*

# 작업 디렉토리 설정
WORKDIR /app

# 현재 디렉토리의 내용을 컨테이너의 /app 디렉토리로 복사
COPY . /app

# 스크립트 실행
CMD ["./build.sh"]