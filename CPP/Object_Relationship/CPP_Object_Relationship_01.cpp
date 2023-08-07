/*
	Object Relationship - 객체 관계

	- Compostition(구성)	part-of
	// 전체의 생명주기 공유
	
	- Aggregation(집합)		has-a
	// 클래스의 일부만 담당
	
	- Association(연계)		uses-a
	// 커플링 관계 (유지보수가 힘듬), friend, 참조 변수를 멤버로 선언
	
	- Dependency(의존)		depend-on
	// 도구로 잠깐 사용

	++ Inheritance(상속)	is-a


									 관계 형태		다른 클래스에 속할수 있는가  멤버의 존재를 클래스가 관리	방향성
   Composition(구성)     part-of     전체/부품                   No                        Yes					단방향
   Aggregation(집합)     has-a       전체/부품                   Yes                       No					단방향
   Association(연계)     uses-a      용도 외엔 무관              Yes                       No				단방향 or 양방향
   Dependency(의존)      depends-on  옹도 외엔 무관              Yes                       Yes					단방향
*/

/*
	결합도는 낮게 (서로 다른 객체간의 의존하는 정도)
	응집도는 높게 (한 모듈, 한 객체 내의 관련있는 정도)
*/
