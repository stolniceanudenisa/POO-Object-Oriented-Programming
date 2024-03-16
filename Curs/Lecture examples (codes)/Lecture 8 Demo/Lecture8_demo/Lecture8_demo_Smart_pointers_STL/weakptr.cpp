#include <iostream>
#include <memory>
#include <vector>
#include <Windows.h>
// -------------------------------------------------------------------------------------------------------------------------------

#define WEAK_PTR
#ifndef WEAK_PTR
class Team;

class Member
{

public:
	void setTeamPtr(const std::shared_ptr<Team>& tp) { this->m_teamPtr = tp; }
	Member() { std::cout << "Member created\n"; }
	~Member() { std::cout << "Member destroyed \n"; }

private:
	std::shared_ptr<Team> m_teamPtr;
};

class Team
{

public:
	void addMember(std::shared_ptr<Member> m) { this->m_members.push_back(m); }
	Team() { std::cout << "Team created \n"; }
	~Team() { std::cout << "Team destroyed \n"; }

private:
	std::vector<std::shared_ptr<Member>> m_members;


};

void exampleSharedPtr()
{
	std::shared_ptr<Member> m1 = std::make_shared<Member>();	// reference count for m1 is 1
	std::shared_ptr<Member> m2 = std::make_shared<Member>();	// reference count for m2 is 1
	std::shared_ptr<Member> m3 = std::make_shared<Member>();	// reference count for m3 is 1

	{
		std::shared_ptr<Team> team = std::make_shared<Team>();	// reference count for team is 1
		team->addMember(m1);		// reference count for m1 is now 2
		team->addMember(m2);		// reference count for m2 is now 2
		team->addMember(m3);		// reference count for m3 is now 2

		m1->setTeamPtr(team);		// reference count for team is now 2
		m2->setTeamPtr(team);		// reference count for team is now 3
		m3->setTeamPtr(team);		// reference count for team is now 4
	}

	int n = 0;

	// what happens at the end of this scope?
	// Will the team be destroyed? Will the members be destroyed?
}
#else

class Team;

class Member
{

public:
	void setTeamPtr(std::weak_ptr<Team> tp) { this->m_teamPtr = tp; }
	Member() { std::cout << "Member created\n"; }
	~Member() { std::cout << "Member destroyed \n"; }

private:
	std::weak_ptr<Team> m_teamPtr;
};

class Team
{

public:
	void addMember(std::shared_ptr<Member> m) { this->m_members.push_back(m); }
	Team() { std::cout << "Team created \n"; }
	~Team() { std::cout << "Team destroyed \n"; }

private:
	std::vector<std::shared_ptr<Member>> m_members;
};
#endif

void exampleWeakPtr()
{
	std::shared_ptr<Member> m1 = std::make_shared<Member>();	// reference count for m1 is 1
	std::shared_ptr<Member> m2 = std::make_shared<Member>();	// reference count for m2 is 1
	std::shared_ptr<Member> m3 = std::make_shared<Member>();	// reference count for m3 is 1

	{
		std::shared_ptr<Team> team = std::make_shared<Team>();	// reference count for team is 1
		team->addMember(m1);		// reference count for m1 is now 2
		team->addMember(m2);		// reference count for m2 is now 2
		team->addMember(m3);		// reference count for m3 is now 2

		m1->setTeamPtr(team);		// reference count for team is still 1
		m2->setTeamPtr(team);		// reference count for team is still 1
		m3->setTeamPtr(team);		// reference count for team is still 1
	}

	int x = 0;
	/*what happens at the end of this scope in this case?
	Will the team be destroyed?
	When will the members be destroyed ?*/
}

int main() {
#ifdef WEAK_PTR
	exampleWeakPtr();
#else
	exampleSharedPtr();
#endif
	_CrtDumpMemoryLeaks();
	system("pause");
	return 0;
}