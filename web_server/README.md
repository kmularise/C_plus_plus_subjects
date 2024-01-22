# 싱글톤 구현
이렇게 구현을 하면 모든 조건을 만족하는 좋은 Singleton 코드가 됩니다.

조건은 다음과 같습니다.
1. 객체를 data영역에 선언해 행여 발생될 데이터의 해제를 방지할 수 있습니다.
2. static Singleton s 변수를 getIncetance() 함수 안에 넣음으로 써 늦은 초기화가 가능해 집니다.
3. 복사생성자, 생성자, 소멸자를 private으로 선언하여 복사, 상속을 못하게 막았습니다.

이렇게 static을 통한 참조를 한다면 포인터로 받아오는 Singleton보다 더 좋은 코드가 될 것입니다.

## nginx 설정파일
nginx
config file
Host, Port
Server name
setup default
limit client body size
Accepted HTTP Methods for the route
autoindex On/Off
redirect
execute CGI (RFC 3275 참고)

## tree 구조
* user
* error_log
* http
	* default_type
	* sendfile
	* keepalive_timeout
* server
	* listen 
	* server_name
	* location /(패턴)
		* root :요청된 파일의 root directory
		* index :디렉토리에 대한 요청이 들어왔을 때 기본적으로 제공할 파일 지정
	* error_page 상태코드, 해당 html파일
	* location - map 구조로 만들면 좋겠다. - std::string map구조 이런식으로?

## 1단계 tree 넣을 키
일단 key value 형태로 json 처럼 파싱하는 걸 담을 것임

일단 std::string map으로 하고 타입캐스팅을 하던지 내부에서 변환을 하던지 하자.

없으면 default 값을 읽어들이게끔 하자