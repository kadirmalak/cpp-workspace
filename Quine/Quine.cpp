#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main()
{
	auto source = vector<string>{
		"#include <iostream>",
		"#include <string>",
		"#include <vector>",
		"",
		"using namespace std;",
		"",
		"int main()",
		"{",
		"    auto source = vector<string>{",
		"    {SRC}",
		"    };",
		"",
		"    for (auto line : source)",
		"    {",
		"        if (line == \"    {SRC}\")",
		"        {",
		"            for (auto line2 : source)",
		"            {",
		"                cout << \"        \" << '\"';",
		"                for (auto ch : line2)",
		"                {",
		"                    if (ch == '\\\\' || ch == '\"') {",
		"                        cout << '\\\\';",
		"                    }",
		"                    cout << ch;",
		"                }",
		"                cout << '\"' << \",\" << endl;",
		"            }",
		"        }",
		"        else {",
		"            cout << line << endl;",
		"        }",
		"    }",
		"",
		"    return 0;",
		"}",
		"",
	};

	for (auto line : source)
	{
		if (line == "    {SRC}")
		{
			for (auto line2 : source)
			{
				cout << "        " << '"';
				for (auto ch : line2)
				{
					if (ch == '\\' || ch == '"') {
						cout << '\\';
					}
					cout << ch;
				}
				cout << '"' << "," << endl;
			}
		}
		else {
			cout << line << endl;
		}
	}

	return 0;
}

