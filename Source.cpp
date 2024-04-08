#include <iostream>
#include <string>
#include <vector>
#include <map>
#include<chrono>
using TimeStamp = std::chrono::system_clock::time_point;

using namespace std;
class Voter;
class Candidate;

class Prototype {
public:
   virtual Prototype* clone()=0;
};

class Admin {
private:
    int adminID;
    string adminName;
    int adminRank;

public:
    string displayFinalResult();
    string displayBallotStatus(int ballotID);
};

class Administrator {
private:
    int userID;
    string userName;
    int userRank;

public:
    vector<Voter> displayVoters();
    int checkVoteCount();
    void addCandidate(string name, string partyName);
    bool deleteCandidate(int candidateID);
};

class Voter {
private:
    int voterID;
    string name;
    bool hasVoted;

public:
    bool authenticate(int voterID);
    void voteFor(Candidate& candidate);
    bool getVotingStatus();
    Voter* clone();
};

class Candidate {
private:
    int candidateID;
    string name;
    string party;
    int numVotes;

public:
    string getCandidateDetails();
    void incrementVotes();
    int getNumVotes();
};

class NotificationPrototype {
private:
    int notificationID;
    string type;
    string content;
    TimeStamp timestamp;

public:
    void sendNotification(int voterID);
    void confirmStamping(TimeStamp ts);
    NotificationPrototype* clone();
};

class BallotPrototype {
private:
    int ballotID;
    vector<Candidate> candidates;

public:
    bool addCandidate(Candidate candidate);
    vector<Candidate> getCandidateList();
    void vote(int candidateID);
    BallotPrototype* clone();
};


class ResultGenerator {
private:

public:
    void calculateResults(vector<BallotPrototype> ballots);
    Candidate declareWinner();
    map<Candidate, int> getElectionResults();
};