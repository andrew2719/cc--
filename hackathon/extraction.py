# importing required modules
from PyPDF2 import PdfReader

contents  = {'TITLE','DOMAIN','DESCRIPTION'}

stoppage_words = ['REQUREMENTS','PARTICULARS','ADDITIONAL REQUIREMENTS']
# creating a pdf reader object
reader = PdfReader('E:\college\coding\programing\cc++\hackathon\Problem Statements.pdf')

# printing number of pages in pdf file
# print(len(reader.pages))

# getting a specific page from the pdf file
# page = reader.pages[0]

# extracting text from page
# text = page.extract_text()

# some pages contains 2 questions also 



extracted_dict = {}

for i in range(0,2):
    page = reader.pages[i]
    text = page.extract_text()

    # count no of 'TITLE' in text
    count = text.count('TITLE')

    if count ==1:
        title = text.split('TITLE:')[1].split('DOMAIN')[0].strip()
        domain = text.split('DOMAIN:')[1].split('DESCRIPTION')[0].strip()
        
        # get the description by splitting if any stoppage word is found and go to the next page
        description = ""
        for word in stoppage_words:
            if word in text:
                description = text.split('DESCRIPTION:')[1].split(word)[0].strip()
        
        # description = text.split('DESCRIPTION')[1].split('REQUIREMENTS')[0]

        extracted_dict[title] = {'DOMAIN':domain,'DESCRIPTION':description}

    else:
        
        title_1 = text.split('TITLE:')[1].split('DOMAIN')[0].strip()
        domain_1 = text.split('DOMAIN:')[1].split('DESCRIPTION')[0].strip()
        description_1 = ""
        for word in stoppage_words:
            if word in text:
                description_1 = text.split('DESCRIPTION:')[1].split(word)[0].strip()
                break
            
        title_2 = text.split('TITLE:')[2].split('DOMAIN')[1].strip()
        domain_2 = text.split('DOMAIN:')[2].split('DESCRIPTION')[1].strip()
        description_2 = ""
        for word in stoppage_words:
            if word in text:
                description_2 = text.split('DESCRIPTION:')[2].split(word)[1].strip()
                break

        extracted_dict[title_1] = {'DOMAIN':domain_1,'DESCRIPTION':description_1}
        extracted_dict[title_2] = {'DOMAIN':domain_2,'DESCRIPTION':description_2}

        

print(extracted_dict)