#include <string>
#include <vector>
#include <map>
#include<chrono>
using TimeStamp = std::chrono::system_clock::time_point;
using namespace std;

class Admin;
class AdministrativeUser;
class Candidate;
class Ballot;
class ResultGenerator;
class Voter;

class Admin : public AdministrativeUser {
    //singleton
    static Admin* instance;
    int adminID;
    string adminName;
    int adminRank;
    Admin();
    Admin(const  Admin&);
    Admin& operator=(const  Admin&);

public:
    static Admin* getInstance();
    string displayFinalResults();
    string displayBallotStatus(int ballotID);
};

class AdministrativeUser {
private:
    string userName;
    int userRank;
    vector<Candidate*> candidates;
public:
    AdministrativeUser();
    AdministrativeUser(string us, int ur);
    void addCandidate(string name, string partyName);
    vector<Voter*> displayVoter();
    bool deleteCandidate(int candidateId);
    int checkVoteCount();
};

class Candidate {
private:
    int candidateID;
    string name;
    string party;
    int numVotes;

public:
    Candidate();
    Candidate(string _name, string _party);
    string getCandidateDetails();
    void incerementVotes();
    int getNumVotes();
};

class Ballot {
private:
    vector<Candidate*> candidates;
public:
    void addCandidate(Candidate* candidate);
    vector<Candidate*> getCandidate();
    void submitVote(int candidateId);
};

class ResultGenerator {
private:
    static ResultGenerator* instance;
    ResultGenerator();
    ResultGenerator(const ResultGenerator&);
    ResultGenerator& operator=(const ResultGenerator&);

public:
    static ResultGenerator* getInstance();
    void calculateResults(vector<Ballot*> ballots);
    Candidate declareWinner();
    map<Candidate, int> getElectionResult();
};

class Notification {
    int notificationId;
    string type;
    string content;
    TimeStamp timestamp;
public:
    void sendNotification(int userId, int notificatiionID, string type, string content, TimeStamp ts);
    void viewNotification(int notificationID);
};

class Voter {
    int voterId;
    string name;
    bool hasVoted;
public:
    bool authenticateVoter();
    void vote(Ballot ballot);
    bool getVotingStatus();
};