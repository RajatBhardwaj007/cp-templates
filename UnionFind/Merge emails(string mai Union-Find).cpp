/*
Question:
Given a list accounts, each element accounts[i] is a list of strings, where the first element accounts[i][0] is a name, and the rest of the elements are emails
representing emails of the account.
Now, we would like to merge these accounts. Two accounts definitely belong to the same person if there is some email that is common to both accounts. Note that
even if two accounts have the same name, they may belong to different people as people could have the same name. A person can have any number of accounts initially, 
but all of their accounts definitely have the same name.
After merging the accounts, return the accounts in the following format: the first element of each account is the name, and the rest of the elements are emails in sorted order.
The accounts themselves can be returned in any order.

Input: 
accounts = [["John", "johnsmith@mail.com", "john00@mail.com"], ["John", "johnnybravo@mail.com"], ["John", "johnsmith@mail.com", "john_newyork@mail.com"], ["Mary", "mary@mail.com"]]

Output:
[["John", 'john00@mail.com', 'john_newyork@mail.com', 'johnsmith@mail.com'],  ["John", "johnnybravo@mail.com"], ["Mary", "mary@mail.com"]]


Soln:

1. The key task here is to connect those emails, and this is a perfect use case for union find.
2. to group these emails, each group need to have a representative, or parent.
3. At the beginning, set each email as its own representative.
4. Emails in each account naturally belong to a same group, and should be joined by assigning to the same parent (let's use the parent of first email in that list);

*/

class Solution {
public:
    vector<vector<string>> accountsMerge(vector<vector<string>>& acts) {
        map<string, string> owner;
        map<string, string> parents;
        map<string, set<string>> unions;
        for (int i = 0; i < acts.size(); i++) {
            for (int j = 1; j < acts[i].size(); j++) {
                parents[acts[i][j]] = acts[i][j]; // hr email ka parent vo khud hai
                owner[acts[i][j]] = acts[i][0]; // hr email ek section mai jo hai, uska owner first element h.
            }
        }
		/*
		  ab neeche jo ho rha h. For example:
		    a b c // now b, c have parent a
			d e f // now e, f have parent d
			g a d // now abc, def all merged to group g

			parents populated after parsing 1st account: a b c
			a->a
			b->a
			c->a

			parents populated after parsing 2nd account: d e f
			d->d
			e->d
			f->d

			parents populated after parsing 3rd account: g a d
			g->g
			a->g
			d->g
		*/
        for (int i = 0; i < acts.size(); i++) {
            string p = find(acts[i][1], parents);
            for (int j = 2; j < acts[i].size(); j++)
                parents[find(acts[i][j], parents)] = p;
        }
		
        for (int i = 0; i < acts.size(); i++)
            for (int j = 1; j < acts[i].size(); j++)
                unions[find(acts[i][j], parents)].insert(acts[i][j]);

        vector<vector<string>> res;
        for (pair<string, set<string>> p : unions) {
            vector<string> emails(p.second.begin(), p.second.end());
            emails.insert(emails.begin(), owner[p.first]);
            res.push_back(emails);
        }
        return res;
    }
private:
    string find(string s, map<string, string>& p) {
        return p[s] == s ? s : find(p[s], p);
    }
};