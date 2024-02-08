import style from './UserSubsectionSelect.module.css'
import { useNavigate, useParams } from "react-router-dom"
import { useEffect, useState } from "react"
import axios from 'axios';

const UserSubsectionSelectPage = () => {
  const navigate = useNavigate();
  const { testTypeId } = useParams();
  const [loading, setLoading] = useState(true);
  const [pageTitle, setPageTitle] = useState(null);
  const [aaCount, setAaCount] = useState(null);
  const [bbCount, setBbCount] = useState(null);
  const [ccCount, setCcCount] = useState(null);
  const [aaTitle, setAaTitle] = useState(null);
  const [bbTitle, setBbTitle] = useState(null);
  const [ccTitle, setCcTitle] = useState(null);
  const [aaLinks, setAaLinks]  = useState(null);
  const [bbLinks, setBbLinks]  = useState(null);
  const [ccLinks, setCcLinks]  = useState(null);

  useEffect( () => {
    const fetchData = async () => {
      try {
        const response = await axios.get('http://localhost:7500/challenges');
        const dataAPI = response.data

        let sectionsArray = ["-", "-", "-"]
        let linksArray = ["-", "-", "-"]
        switch (testTypeId){
          case 'education':
            setPageTitle("Образование")
            sectionsArray = ["Физика", "Математика", "Безопасность жизнедеятельности"]
            linksArray    = ["phys",   "math", "safety"]
            break

          case 'psycho':
            setPageTitle("Психология")
            sectionsArray = ["Когнитивизм", "Психоанализ", "Бихевиоризм"]
            linksArray    = ["cognitive",   "psychoanalysis", "behaviourism"]
            break

          case 'funny':
            setPageTitle("Развлечения")
            sectionsArray = ["Ирония", "Сатира", "Анекдоты"]
            linksArray    = ["irony",   "satire", "anekdots"]
            break
          default:
        }

        setAaTitle(sectionsArray[0])
        setBbTitle(sectionsArray[1])
        setCcTitle(sectionsArray[2])
        setAaLinks(linksArray[0])
        setBbLinks(linksArray[1])
        setCcLinks(linksArray[2])

        sectionsArray.map( (section) => {
          const count = dataAPI.filter(item => item.section === section).length;
          switch (section){
            case sectionsArray[0]:
              setAaCount(count)
              break

            case sectionsArray[1]:
              setBbCount(count)
              break

            case sectionsArray[2]:
              setCcCount(count)
              break
            default:
          }
          return count
        })
        setLoading(false)
      } catch (error) {
        console.error('Error fetching data:', error);
      }
    };
    fetchData();
  }, [testTypeId])

  if (loading){
    return (
      <div className={style.bodyStyle}></div>
    )
  }

  return (
      <div className={style.bodyStyle}>
        <div className={style.hText}>
          {pageTitle}
        </div>
        <div className={style.imageBox}>
          <div>
            <img src={`./../${aaLinks}.png`} alt="Physics.png" onClick={ ()=>navigate(`/user-challenge-select/${aaLinks}`)}/>
            <div className={style.imageCaption} onClick={ ()=>navigate(`/user-challenge-select/${aaLinks}`)}>{aaTitle} ({aaCount})</div>
          </div>
          <div>
            <img src={`./../${bbLinks}.png`} alt="Mathematics.png" onClick={ ()=>navigate(`/user-challenge-select/${bbLinks}`)}/>
            <div className={style.imageCaption} onClick={ ()=>navigate(`/user-challenge-select/${bbLinks}`)}>{bbTitle} ({bbCount})</div>
          </div>
          <div>
            <img src={`./../${ccLinks}.png`} alt="Life safety.png" onClick={ ()=>navigate(`/user-challenge-select/${ccLinks}`)}/>
            <div className={style.imageCaption} onClick={ ()=>navigate(`/user-challenge-select/${ccLinks}`)}>{ccTitle} ({ccCount})</div>
          </div>
        </div>
        <div className={style.placeButton}>
          <button className={style.flatButton} onClick={ ()=>navigate('/')} >Back to Home</button>
        </div>
      </div>
  );
}

export default UserSubsectionSelectPage;
