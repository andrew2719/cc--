from PyPDF2 import PdfReader

reader = PdfReader('E:\college\coding\programing\cc++\hackathon\Problem Statements.pdf')

needed_words_as_keys = ['TITLE','DOMAIN','DESCRIPTION']

stoppage_words = ['REQUIREMENTS','PARTICULARS','ADDITIONAL REQUIREMENTS','REQUIREME NTS']


extracted_matter = {}

for i in range(len(reader.pages)):
    page = reader.pages[i]
    text = page.extract_text()
    # print(text)
    print(i)
    if text.count('TITLE:') == 1:
        title = text.split('TITLE:')[1].split('DOMAIN')[0].strip()
        domain = text.split('DOMAIN:')[1].split('DESCRIPTION')[0].strip()
        description = ""
        for word in stoppage_words:
            if word in text:
                description = text.split('DESCRIPTION:')[1].split(word)[0].strip()
                break

        extracted_matter[title] = ['DOMAIN: '+domain,'DESCRIPTION: '+description]
    print(description)

#print(title)
#print(domain)
# print(description)




