#include <iostream>
#include <vector>
#include <string>
#include <limits>

using namespace std;

// Structure to represent a loan applicant
struct Applicant {
    string name;
    int creditScore;        // Credit score of the applicant
    int employmentYears;    // Number of years of stable employment
    bool loanApproved;      // Loan approval status
};

// Function to evaluate loan applications
void evaluateApplications(vector<Applicant>& applicants, int creditScoreThreshold, int employmentYearsThreshold) {
    for (auto& applicant : applicants) {
        // Rule: Credit score above threshold and stable employment history
        if (applicant.creditScore > creditScoreThreshold && applicant.employmentYears >= employmentYearsThreshold) {
            applicant.loanApproved = true;
        } else {
            applicant.loanApproved = false;
        }
    }
}

// Function to display the result of the credit approval process
void displayResults(const vector<Applicant>& applicants) {
    cout << "\n=== Credit Approval Results ===\n";
    cout << "---------------------------------\n";
    for (const auto& applicant : applicants) {
        cout << "Applicant: " << applicant.name
             << "\n - Credit Score: " << applicant.creditScore
             << "\n - Employment History: " << applicant.employmentYears << " years"
             << "\n - Loan Status: " << (applicant.loanApproved ? "Approved" : "Rejected") << "\n";
        cout << "---------------------------------\n";
    }
}

// Function to add applicants dynamically
void addApplicants(vector<Applicant>& applicants) {
    int numApplicants;
    cout << "Enter the number of applicants: ";
    while (!(cin >> numApplicants) || numApplicants <= 0) {
        cout << "Invalid input. Please enter a positive integer: ";
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }

    for (int i = 0; i < numApplicants; ++i) {
        cout << "\nEnter details for applicant " << i + 1 << ":\n";
        Applicant applicant;

        // Name
        cout << "Name: ";
        cin.ignore();
        getline(cin, applicant.name);

        // Credit Score
        cout << "Credit Score: ";
        while (!(cin >> applicant.creditScore) || applicant.creditScore < 0) {
            cout << "Invalid input. Please enter a valid positive credit score: ";
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }

        // Employment History
        cout << "Years of Stable Employment: ";
        while (!(cin >> applicant.employmentYears) || applicant.employmentYears < 0) {
            cout << "Invalid input. Please enter a valid positive number of years: ";
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }

        // Add applicant to the list
        applicants.push_back(applicant);
    }
}

// Main function
int main() {
    vector<Applicant> applicants;

    cout << "=== Welcome to the Credit Approval System ===\n";

    // Add applicants dynamically
    addApplicants(applicants);

    // Set thresholds for approval
    int creditScoreThreshold, employmentYearsThreshold;

    cout << "\nSet the minimum credit score required for loan approval: ";
    while (!(cin >> creditScoreThreshold) || creditScoreThreshold < 0) {
        cout << "Invalid input. Please enter a positive credit score threshold: ";
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }

    cout << "Set the minimum years of stable employment required for loan approval: ";
    while (!(cin >> employmentYearsThreshold) || employmentYearsThreshold < 0) {
        cout << "Invalid input. Please enter a positive number for employment years: ";
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }

    // Evaluate loan applications
    evaluateApplications(applicants, creditScoreThreshold, employmentYearsThreshold);

    // Display results
    displayResults(applicants);

    cout << "\nThank you for using the Credit Approval System. Goodbye!\n";

    return 0;
}
